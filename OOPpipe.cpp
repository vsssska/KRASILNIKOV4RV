#include <iostream>
#include <functional> // для std::function

class PipePressure {
private:
    double q; // flow_rate
    double h; // height
    double rho; // density
    double p; // pressure
    double p_n; // prev_pressure

public:
    PipePressure(double flow_rate, double height, double density, double pressure, double prev_pressure = 0)
        : q(flow_rate), h(height), rho(density), p(pressure), p_n(prev_pressure) {}

    double eq() const {
        return (9.81 * rho * q * h) / (p * 1000);
    }

    double withPrevious(std::function<double()> f1) const {
        std::cout << "Previous pressure\n";
        return (9.81 * rho * q * h) / (p_n * 1000 * f1());
    }

    double calc(std::function<double()> f1) const {
        if (p_n == 0) {
            return eq();
        } else {
            return withPrevious(f1);
        }
    }

    double compute() const {
        return calc(std::bind(&PipePressure::eq, this));
    }
};

int main() {
    PipePressure calc(12, 12, 3, 5, 12);
    std::cout << calc.compute() << std::endl;
    return 0;
}
