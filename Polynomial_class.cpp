#include <iostream>
#include <vector>
#include <cmath>

class Polynomial {
private:
    std::vector<int> coeffs; 

public:
    
    Polynomial(int degree = 0) : coeffs(degree + 1, 0) {}

    // Constructor: 
    Polynomial(const std::vector<int>& coefficients) : coeffs(coefficients) {}

    
    int degree() const {
        return coeffs.size() - 1;
    }

    //  [] operator to access coefficients
    int& operator[](int index) {
        return coeffs[index];
    }

    // addition operator
    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = std::max(degree(), other.degree());
        std::vector<int> resultCoeffs(maxDegree + 1, 0);

        for (int i = 0; i <= maxDegree; ++i) {
            if (i <= degree()) resultCoeffs[i] += coeffs[i];
            if (i <= other.degree()) resultCoeffs[i] += other.coeffs[i];
        }

        return Polynomial(resultCoeffs);
    }

    // subtraction operator
    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = std::max(degree(), other.degree());
        std::vector<int> resultCoeffs(maxDegree + 1, 0);

        for (int i = 0; i <= maxDegree; ++i) {
            if (i <= degree()) resultCoeffs[i] += coeffs[i];
            if (i <= other.degree()) resultCoeffs[i] -= other.coeffs[i];
        }

        return Polynomial(resultCoeffs);
    }

    //  multiplication operator
    Polynomial operator*(const Polynomial& other) const {
        int newDegree = degree() + other.degree();
        std::vector<int> resultCoeffs(newDegree + 1, 0);

        for (int i = 0; i <= degree(); ++i) {
            for (int j = 0; j <= other.degree(); ++j) {
                resultCoeffs[i + j] += coeffs[i] * other.coeffs[j];
            }
        }

        return Polynomial(resultCoeffs);
    }

    // Evaluation of the polynomial at a given value of x
    int evaluate(int x) const {
        int result = 0;
        for (int i = 0; i <= degree(); ++i) {
            result += coeffs[i] * std::pow(x, i);
        }
        return result;
    }

    // input operator
    friend std::istream& operator>>(std::istream& in, Polynomial& poly) {
        int deg;
        std::cout << "Enter the degree of the polynomial: ";
        in >> deg;
        poly.coeffs.resize(deg + 1);

        std::cout << "Enter " << deg + 1 << " coefficients (from lowest to highest degree): ";
        for (int i = 0; i <= deg; ++i) {
            in >> poly.coeffs[i];
        }
        return in;
    }

    //  output operator
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
        bool first = true;
        for (int i = poly.degree(); i >= 0; --i) {
            if (poly.coeffs[i] != 0) {
                if (!first) out << " + ";
                out << poly.coeffs[i];
                if (i > 0) out << "x^" << i;
                first = false;
            }
        }
        if (first) out << "0"; // In case of a zero polynomial
        return out;
    }
};

int main() {
    Polynomial p1, p2;
    
    std::cout << "Enter first polynomial:\n";
    std::cin >> p1;
    
    std::cout << "Enter second polynomial:\n";
    std::cin >> p2;
    
    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    std::cout << "\nFirst Polynomial: " << p1;
    std::cout << "\nSecond Polynomial: " << p2;
    std::cout << "\nSum: " << sum;
    std::cout << "\nDifference: " << diff;
    std::cout << "\nProduct: " << prod;

    int x;
    std::cout << "\nEnter a value of x to evaluate first polynomial: ";
    std::cin >> x;
    std::cout << "p1(" << x << ") = " << p1.evaluate(x) << "\n";

    return 0;
}
