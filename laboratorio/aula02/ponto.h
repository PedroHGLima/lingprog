class Ponto {
    public:
    Ponto(double a=1, double b=1, double c=1);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    double getX();
    double getY();
    double getZ();
    
    private:
    double x, y, z;
};
