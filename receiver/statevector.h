


class Statevector {
  public:
    std::vector < int > kernel;
    Statevector(int[3]);
    Statevector operator+= (const Statevector&);
    Statevector operator-= (const Statevector&);
    Statevector operator*= (const double);
    Statevector operator/= (const double);
};

inline Statevector operator+ (Statevector, const Statevector&);
inline Statevector operator- (Statevector, const Statevector&);
inline Statevector operator* (Statevector, double);
inline Statevector operator/ (Statevector, double);

std::ostream& operator<<(std::ostream&, const T& obj);
std::istream& operator>>(std::istream&, T&);
