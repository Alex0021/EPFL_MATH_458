class Planet {

public:
  Planet();                   // constructor
  ~Planet();                  // destructor
  void move(double delta[3]); // a method

private:
  // a pointer member
  double *coords;
};