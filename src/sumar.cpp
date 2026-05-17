#include "sumar.h"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <sstream>

#include <nlohmann/json.hpp>

void Sumar::inregistreaza(const std::string& titluCard, const std::string& alegere) {
    decizii.emplace_back(titluCard, alegere);
}

void Sumar::seteazaCheie(const std::string& cheie) {
    apiKey = cheie;
}

void Sumar::seteazaFinal(int bani, int cap, int alin, const std::string& ending) {
    finalBani = bani;
    finalCap = cap;
    finalAlin = alin;
    endingText = ending;
}

bool Sumar::areCheie() const {
    return !apiKey.empty();
}

std::string Sumar::construiestePrompt() const {
    std::ostringstream os;
    os << "Joc: TAKEOFF, simulator cursa AI 2023-2026. Jucatorul conduce un lab american.\n";
    os << "Decizii in ordine cronologica:\n";
    for (const auto& d : decizii) {
        os << "- " << d.first << " | a ales: \"" << d.second << "\"\n";
    }
    os << "\nStats finale: bani=" << finalBani
       << ", capabilitate=" << finalCap
       << ", aliniere=" << finalAlin << "\n";
    os << "Ending atins: " << endingText << "\n\n";
    os << "Scrie 6-8 propozitii in romana, ton funny dar nu cringe. Acopera:\n"
       << "- Ce tip de CEO esti (\"esti tipul care...\")\n"
       << "- O alegere remarcabila (cea mai buna sau cea mai proasta)\n"
       << "- A fost comeback sau colaps treptat?\n"
       << "- Verdict final scurt\n"
       << "Stil: direct, fara emoji, fara \"Sigur!\" sau \"Iata!\", romana naturala, fara diacritice.";
    return os.str();
}

std::string Sumar::apeleazaGemini(const std::string& prompt) const {
    namespace fs = std::filesystem;
    const fs::path tmpReq = fs::temp_directory_path() / "takeoff_gemini_req.json";
    const fs::path tmpResp = fs::temp_directory_path() / "takeoff_gemini_resp.json";

    nlohmann::json req = {
        {"contents", nlohmann::json::array({
            nlohmann::json{
                {"parts", nlohmann::json::array({
                    nlohmann::json{{"text", prompt}}
                })}
            }
        })}
    };

    {
        std::ofstream f(tmpReq);
        if (!f) return "";
        f << req.dump();
    }

    std::ostringstream cmd;
    cmd << "curl -s -X POST -H \"Content-Type: application/json\" "
        << "--data-binary @\"" << tmpReq.string() << "\" "
        << "\"https://generativelanguage.googleapis.com/v1beta/models/gemini-flash-lite-latest:generateContent?key="
        << apiKey << "\" "
        << "-o \"" << tmpResp.string() << "\"";

    const int rc = std::system(cmd.str().c_str());
    fs::remove(tmpReq);

    if (rc != 0) {
        fs::remove(tmpResp);
        return "";
    }

    nlohmann::json resp;
    {
        std::ifstream rf(tmpResp);
        if (!rf) {
            fs::remove(tmpResp);
            return "";
        }
        try {
            rf >> resp;
        } catch (...) {
            fs::remove(tmpResp);
            return "";
        }
    }
    fs::remove(tmpResp);

    try {
        return resp["candidates"][0]["content"]["parts"][0]["text"].get<std::string>();
    } catch (...) {
        return "";
    }
}

std::string Sumar::genereaza() const {
    if (apiKey.empty() || decizii.empty()) return "";
    return apeleazaGemini(construiestePrompt());
}
