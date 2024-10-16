class Planet {

public:
  Planet();                   // constructor
  ~Planet();                  // destructor
  void move(double delta[3]); // a method

private:
  double coords[3]; // a member
};