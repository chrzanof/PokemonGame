//
// Created by Filip on 14.06.2022.
//

#ifndef POKEMONGAME_ELEMENTAL_H
#define POKEMONGAME_ELEMENTAL_H
#include <iostream>
#include <string>
#include <vector>

class Elemental {
    std::string name;
    std::vector<Elemental> weaknesses;
    std::vector<Elemental> strengths;
public:
    static constexpr double WEAKNESS_MODIFIER = 0.75;
    static constexpr double STRENGTH_MODIFIER = 1.25;

    Elemental(const std::string &name);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Elemental> &getWeaknesses() const;

    void setWeaknesses(const std::vector<Elemental> &weaknesses);

    const std::vector<Elemental> &getStrengths() const;

    void setStrengths(const std::vector<Elemental> &strengths);

    void addWeakness(Elemental elemental);

    void addStrength(Elemental elemental);

    double returnModifier(const Elemental &elemental);



};


#endif //POKEMONGAME_ELEMENTAL_H
