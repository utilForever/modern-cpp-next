#include <iostream>
using namespace std;
void func( int a )
{
cout << "func - int " << endl;
}
void func( double *p )
{
cout << "func - double * " << endl;
}
int main()
{
func( static_cast<double*>(0) );
func( 0 );
func( nullptr);
getchar();
return 0;
}