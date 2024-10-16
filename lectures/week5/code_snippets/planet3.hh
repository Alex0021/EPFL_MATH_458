class Planet {

public:
  Planet();                          // constructor
  Planet(double param1, int param2); // second constructor
  Planet(const Planet &);            // copy constructor
  ~Planet();                         // destructor
  void move(double delta[3]);        // a method

private:
  // a pointer member
  double *coords;
};