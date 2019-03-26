# Some things learned as I work on making a decent ray tracer


## Vectors
* We can add a fourth dimension to the vector (x,y,z), called w, therefore (x,y,z,w)
  * this is called the "projective space"
  * the reason is because it allows us to encode the translation in a 4x4 matrix
  * by keeping w=1, we can simply multiply a matrix with a translation and the values that sum with w are the x,y,z translations



## Matrices
* for 3D coordinates we can use 4x4 matrices to encode transformations
* Finding the inverse is frustrating....
* We can either use Row Major Order or Column Major Order
  * this is the order by which we multiply our vector to a matrix
  * Row Major Order is preffered as it maximizes the use of CPU cache due to sequential memory usage

