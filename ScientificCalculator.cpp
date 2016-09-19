#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include <sstream>
using namespace std ;
double sqrt(double x);   // done
long double logx(double x,double b);
long double TenPowerX(double x);
long double apowerx(double a,double x);
double Nroot(double n , double x);
double sqrt(double x);
double ln(double x);

// islam_emam_G3_20140056_ Hussien hamdy_G4_20140103


double x = 0 ;
static double mp=0, mn = 0 , mr = 0  ,*result = &x  , mc = 0 , y ;

double ms ;



static string str1 , str2 ;

double power(double base, int pow)    // done
{
    double var = 1 ;
    for (int i = 1 ; i<= pow ; i++)
    {
        var *= base ;
    }
    return var ;
}

long double factorial(int n)    // done
{
    long double f = 1 ;
    for (int i = n ; i >0 ; i--)
        f*=i ;
    return f ;
}

double absolute(double n)   // done
{
    double abs ;
    if (n < 0) abs = n*-1 ;
    else if(n>0) abs = n ;
    else abs = 0 ;
    return abs ;
}

double sin(double x) // done
{
    x = (x*(22.0/7))/180.0 ;

    double sigma = 0 ;

    if(x == 180 || x == 360) return 0 ;
    else
    {
        for(int n = 0 ; n <= 15 ; n++)
        {
            sigma += (power(-1,n)*(power(x , 2*n+1)))/factorial(2*n+1);
        }
        return sigma ;
    }
}

long double cos(double x)
{
    if(x==270)return 0 ;

    double cos = sin(90-x) ;

    return cos ;
}

double tan(double x)      // done
{
    double tan = sin(x)/cos(x) ;
    return tan ;
}

double sinh(double x)     // done
{
    double Sigma = 0 ;
    for(int i = 0 ; i<=10; i++)
        Sigma += (1.0*(power(x,2*i+1))/factorial(2*i+1));
    return Sigma ;
}

double cosh(double x)    // done
{
    double cosh=0;
    for(int i=0; i<=10; i++)
    {
        cosh+= (1.0*(power(x,2*i))/(factorial(2*i)));
    }
    return cosh;
}

double tanh(double x)    // done
{
    double tanh = sinh(x)/cosh(x) ;
    return tanh ;
}

double exp(double x)    // done
{
    double exp1  = 0 ;
    for(int i = 0 ; i<20 ; i++)
        exp1  += (power(x,i)/factorial(i)) ;
    return exp1  ;
}

double asin(double x)
{

    double Sigma = 0 ;
    if(x==1)return 90 ;
    for (int n = 0 ; n<=20; n++)
        Sigma += ((factorial(2*n)*power(x,((2*n)+1)))/(power(4,n)*power(factorial(n),2)*(2*n+1)));
    Sigma = (Sigma*180)/(22/7.0);
    return Sigma;
}

double acos(double x)
{
    double arccos = 90 - asin(x);
    return arccos ;
}

double atan(double x)
{
    double arctan = 0 ;
    for(int i = 0 ; i<= 18 ; i++)
        arctan += ((power((-1),i)*power(x,(2*i+1)))/(2*i+1)) ;
    arctan = (arctan*180)/(22/7.0);
    return arctan ;
}


double ln(double x)  // done
{

    double ln =0 ;
    if(x>0)
    {
        for(int n = 1; n<=1000 ; n++)
            ln += (1.0/n*(power((x-1)/x,n)));
        return ln ;
    }
    else
    {
        cout<<"Math Error"<<endl;
    }

}

double sqrt(double x)     // done
{
    double sqrt = exp((1.0/2)*ln(x));
    return sqrt ;
}

double Nroot(double n , double x)
{
    double root = exp(1.0/n*ln(x));
    return root ;
}

long double apowerx(double a,double x)
{

    double ax=0;
    for(int i=0; i<=100; i++)
    {
        ax+=power((x*ln(a)),i)/factorial(i);
    }
    return ax;
}

long double TenPowerX(double x)
{
    return apowerx(10,x);
}

long double log10(double x)
{
    if(x>0)
    {
        double logbx=ln(x)/ln(10);
        return logbx;
    }
    else
        cout<<"Math Error"<<endl;
}

long double log(double b,double x)
{
    if(x>0)
    {
        double logbx=ln(x)/ln(b);
        return logbx;
    }
    else
        cout<<"Math Error"<<endl;
}

bool isnum(string str2)
{
    bool state2 = false ;
    for(int i = 0 ; i < (str2.length()); i++)
    {
        if(isdigit(str2[i]))
            state2 = true ;
    }
    return state2 ;
}


int main()
{
    cout  << fixed << setprecision(2);
    cout << "*****************************************************************************\n\n" ;
    cout << "  Enter the following syntex for scientific calculator :*********************\n\n" ;
    cout << "  ::{  sin - cos - tan - asin - acos - atan - sinh - cosh - tanh }*********::\n\n" ;
    cout << "  ::{  ln - exp - log10 - log - tenpower - x^y - ! (~factorial)- sqrt}*****::\n\n" ;
    cout << "  ::{  nroot - abs - ^   (~power) math operations (+  , - , * , / )}*******::\n\n" ;
    cout << "  ::{  MS ,  MR ,  MC ,  M+  ,  M-  ,to remove the memory input MC  }******::\n\n" ;
    cout << "  ::{  to remove the  number input 'C' }***********************************::\n\n" ;
    cout << "*****************************************************************************\n\n" ;
    cout << "Input degrees or radians : \n";
    cin  >> str1 ;
    system("CLS");

    cout << "Enter a number : \n" ;

    cout << 0 << "\b" ;

    bool state = false ;

    cin >> x ;

    while(true)
    {


        system("CLS");

        if(str2=="MR")
            cout << mr << endl ;


        if(str2=="=" || !state)
        {
            cout << *result << endl ;
        }

        cin >> str2 ;

        if( (str2=="+") || (str2 =="-") || (str2=="*") || (str2=="/"))
        {
            if(str2=="+")
            {

                cin >> y ;
                *result += y ;
            }
            if (str2=="*")
            {
                cin >> y ;
                *result *= y ;
            }
            if(str2=="/")
            {
                cin >> y ;
                *result /= y ;
            }
            if(str2=="-")
            {
                cin >> y ;
                *result -= y ;
            }
            system("CLS");

        }


        else if(str2=="C")
        {
            x = 0 ;
            system("CLS");
            cout << 0 << "\b" ;
            cin >> x ;

        }

        else if(str2=="MS")
        {
            const double s = *result ;
            ms = s ;
            mr = ms ;
        }


        else if(str2=="MC")
        {
            ms = 0 ;
            mr = ms ;
            system("CLS");
            cout << mr << "\b" ;
        }

        else if(str2=="MR")
        {
            system("CLS");
            cout << ms << endl ;

            cin >> str2 ;

            //  if(str2=="M+")

        }
        else if ( str2=="M+")
        {
            cin >> mp ;
            system("CLS");
            cout << mp ;
            mp = ms +  mp ;
            ms = mp ;

        }
        else if ( str2=="M-")
        {
            cin >> mn ;
            system("CLS");
            cout << mn ;
            mn = ms -  mn ;
            ms = mn ;
        }
        else if(isnum(str2))
        {
            double s ;

            stringstream turn ;
            turn << str2;
            turn >> s;
            *result=s;
        }

        else
        {
            if(str1=="degrees"){
            if(str2=="sin")  *result= sin(x) ;
            if(str2=="cos")  *result= cos(x) ;
            if(str2=="tan")  *result = tan(x) ;
            if(str2=="asin") *result = asin(x) ;
            if(str2=="acos") *result = acos(x)  ;
            if(str2=="atan") *result = atan(x) ;
        }

        else
        {

            if(str2=="sin")   *result=sin(x*(180)/(22.0/7));
            if(str2=="cos")   *result=cos(x*(180)/(22.0/7));
            if(str2=="tan")   *result=tan(x*(180)/(22.0/7));
            if(str2=="asin") *result = ((asin(x)*(22/7.0))/180.0) ;
            if(str2=="acos") *result = ((sin(x)*(22/7.0))/180.0 ) ;
            if(str2=="atan") *result = ((atan(x)*(22/7.0))/180.0) ;


        }

        if(str2=="sinh") *result = sinh(x)  ;
        if(str2=="cosh") *result = cosh(x)  ;
        if(str2=="tanh") *result = tanh(x)  ;
        if(str2=="ln")  *result = ln(x) ;
        if(str2=="exp")*result = exp(x);
        if(str2=="abs")*result = absolute(x);
        if(str2=="log10") *result = log10(x);
        if(str2=="sqrt")*result = sqrt(x);
        if(str2=="tenpower") *result = TenPowerX(x);
        if(str2=="!") *result = factorial(x);

        // two paramters
        if(str2=="log")
        {
            cin >> y ;
            *result = log(x,y) ;
        }
        if(str2=="nroot")
        {
            cin >> y ;
            *result = Nroot(x , y) ;
        }
        if(str2=="^")
        {
            cin >> y ;
            *result = power(x,y);
        }
        if(str2=="x^y")
        {
            cin >> y ;
            *result = apowerx(x,y);
        }

    }



}
return 0 ;
}





  