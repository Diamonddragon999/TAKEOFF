#ifndef OOP_SUMAR_H
#define OOP_SUMAR_H

#include <string>
#include <vector>

class Sumar {
public:
    void inregistreaza(const std::string& titluCard, const std::string& alegere);
    void seteazaCheie(const std::string& cheie);
    void seteazaFinal(int bani, int cap, int alin, const std::string& ending);
    bool areCheie() const;
    std::string genereaza() const;

private:
    std::vector<std::pair<std::string, std::string>> decizii;
    std::string apiKey;
    std::string endingText;
    int finalBani{0};
    int finalCap{0};
    int finalAlin{0};

    std::string construiestePrompt() const;
    std::string apeleazaGemini(const std::string& prompt) const;
};

#endif
