#include<iostream>

//exception and type conversions

struct Base {
    Base(){}
    Base(const Base&){
        std::cout <<"copy Base\n";

    }
};

struct Derived : public Base {
    Derived(){}
    Derived(const Derived&){
        std::cout <<"copy Derived\n";
    }
};

void f(){
    throw Derived();
}


int g(){

    try
    {
        f();
    }
    catch(double x)
    {
        std::cerr <<"caught double\n" << '\n';
    }
    catch(long long x)
    {
        std::cerr <<"caught long long\n" << '\n';
    }
    catch(unsigned int x)
    {
        std::cerr <<"caught unsigned int\n" << '\n';
    }
    catch(int x)
    {
        std::cerr <<"caught  int\n" << '\n';
    }
    catch(Base& b)
    {
        std::cout << "caught Base\n";
        throw;
    } catch (Derived& d) {
        std::cout << "caught Derived\n";
    }
    catch (...) {
        std::cout << "caught ...\n";
    }


    return 0;
}

int main(){

try
{
    g();
}
catch(Derived& d)
{
    std::cerr <<"caught main" << '\n';
}


    return 0;
}