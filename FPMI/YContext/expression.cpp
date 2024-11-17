#include <iostream>
#include <memory>
#include <string>

class Expression {
public:
    virtual int Evaluate() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~Expression() {}
};

using ExpressionPtr = std::shared_ptr<Expression>;
// using Const = const;
class ExpressionSum : public Expression {
    std::string result;
    int x_,y_;
public:
bool const_check(){
        return false;
    }
    ExpressionSum(int x,int y)
        : x_(x),y_(y)
    {
        result = std::to_string(x_);
        result+='+';
        result+= std::to_string(y_);
    }
    ExpressionSum(ExpressionPtr ex1, int y)
        : x_(ex1->Evaluate()), y_(y) {
            result = ex1->ToString();
            result+='+';
            result+= std::to_string(y_);
        }

    ExpressionSum(int x, ExpressionPtr ex2)
        : x_(x), y_(ex2->Evaluate()) {
            result = std::to_string(x_);
            result+='+';
            result+=  ex2->ToString() ;
        }
    ExpressionSum(ExpressionPtr ex1, ExpressionPtr ex2)
        : x_(ex1->Evaluate()), y_(ex2->Evaluate()) {
            result =  ex1->ToString();
            result+='+';
            result+=  ex2->ToString();
        }
    int Evaluate() const override 
    {
        return x_ + y_;
    }
    std::string ToString() const override {
        return result;
    }
};

class ExpressionMulti : public Expression {
    std::string result;
    int x_,y_;
public:
bool const_check(){
        return false;
    }
    ExpressionMulti(int x, int y)
        : x_(x), y_(y) {
            result = std::to_string(x_);
            result+='*';
            result+= std::to_string(y_);
        }
    
    ExpressionMulti(ExpressionPtr ex1, int y)
        : x_(ex1->Evaluate()), y_(y) {
            result = '(' + ex1->ToString() + ')';
            result+='*';
            result+= std::to_string(y_);
        }

    ExpressionMulti(int x, ExpressionPtr ex2)
        : x_(x), y_(ex2->Evaluate()) {
            result = std::to_string(x_);
            result+='*';
            result+= '(' + ex2->ToString() + ')';
        }
    ExpressionMulti(ExpressionPtr ex1, ExpressionPtr ex2)
        : x_(ex1->Evaluate()), y_(ex2->Evaluate()) {
            result = '(' + ex1->ToString() + ')';
            result+='*';
            result+= '(' + ex2->ToString() + ')';
        }

    int Evaluate() const override 
    {
        return x_*y_;
    }
    std::string ToString() const override {
        return result;
    }
};

class ExpressionConst : public Expression {
    int x_;
public:
    bool const_check(){
        return true;
    }
    ExpressionConst(int x) : x_(x){
    }
    int Evaluate() const override 
    {
        return reinterpret_cast<const int>(x_);
    }
    std::string ToString() const override {
        return std::to_string(x_);
    }
};

ExpressionPtr Sum(ExpressionPtr ex1,ExpressionPtr ex2){
    ExpressionSum Esum(exc1,ex2);
    return std::make_shared<ExpressionSum>(Esum);
}
ExpressionPtr Product(ExpressionPtr ex1,ExpressionPtr ex2){
    if(ex1.use_c)
    ExpressionMulti Emulty(exc1,ex2);
    return std::make_shared<ExpressionMulti>(Emulty);
}

ExpressionPtr Const(int x) {
    ExpressionConst Econst(x);
    return std::make_shared<ExpressionConst>(Econst);
}


int main() {
    ExpressionPtr ex1 = Sum(Product(Const(3), Const(4)), Const(5));
    std::cout << ex1->ToString() << "\n";  // 3 * 4 + 5
    std::cout << ex1->Evaluate() << "\n";  // 17

    ExpressionPtr ex2 = Product(Const(6), ex1);
    std::cout << ex2->ToString() << "\n";  // 6 * (3 * 4 + 5)
    std::cout << ex2->Evaluate() << "\n";  // 102
}