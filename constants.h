#include <string>
#include <vector>

bool isConstant(std::string s) {
    std::vector<std::string> constants = {
        "$PI",
        "$E",
        "$GRAVITY",
        "$SPEED_OF_LIGHT",
        "$AVOGADRO",
        "$BOLTZMANN",
        "$PLANCK",
        "$ELECTRON_MASS",
        "$PROTON_MASS",
        "$NEUTRON_MASS",
        "$ELECTRON_CHARGE",
        "$PROTON_CHARGE",
        "$NEUTRON_CHARGE",
        "$TAU",
        "$MU0",
        "$EPS0",
        "$C",
        "$K"
    };


    for (auto c : constants) {
        if (s == c) {
            return true;
        }
    }
    return false;
}

float getConstantValue(std::string s) {
    std::vector<std::string> constants = {
        "$PI",
        "$E",
        "$GRAVITY",
        "$SPEED_OF_LIGHT",
        "$AVOGADRO",
        "$BOLTZMANN",
        "$PLANCK",
        "$ELECTRON_MASS",
        "$PROTON_MASS",
        "$NEUTRON_MASS",
        "$ELECTRON_CHARGE",
        "$PROTON_CHARGE",
        "$NEUTRON_CHARGE",
        "$TAU",
        "$MU0",
        "$EPS0",
        "$C",
        "$K"
    };

    std::vector<float> values = {
        3.141592653589793,
        2.718281828459045,
        9.80665,
        299792458.0,
        6.022140857e23,
        1.3806488e-23,
        6.62606957e-34,
        9.10938291e-31,
        1.672621777e-27,
        1.672621777e-27,
        1.6021766208e-19,
        1.6021766208e-19,
        1.6021766208e-19,
        2 * 3.141592653589793,
        1.2566370614e-6,
        8.854187817e-12,
        299792458.0,
        1.3806488e-23
    };

    for (int i = 0; i < constants.size(); i++) {
        if (s == constants[i]) {
            return values[i];
        }
    }

    return 0;
}