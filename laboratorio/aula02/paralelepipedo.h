class Paralelepipedo {
public:
    Paralelepipedo(double a, double b, double c);
    void setX(double a);
    void setY(double b);
    void setZ(double c);
    
    double getVolume();
    
private:
    double x, y, z;
    double computeVolume();
};
