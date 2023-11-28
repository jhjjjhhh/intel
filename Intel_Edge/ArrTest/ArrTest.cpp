#include <iostream>

using namespace std;

template <typename T>
class ArrTest
{
    T* arr;
    int Len;  // 배열 요소의 수
private:
public:
    ArrTest(int size) : Len(size)
    {
        arr = new T[size];
    }
    ~ArrTest()
    {
        delete arr;
    }
    int length()
    {
        return Len;
    }
    T& operator[](int idx)   // calling sequence : arr[n]
    {
        if (idx<0 || idx > Len - 1)
        {
            std::cout << "Out of bound\n"; exit(1);
        }
        return arr[idx];
    }
    void show()
    {
        int i;
        printf("{");
        for (i = 0; i < Len - 1; i++)
            std::cout << arr[i] << ",";    std::cout << arr[i];
        printf(" }\n");
    }
    ArrTest& append(int size)
    {
        T* arr1 = new T[Len + size];  // 확장된 메모리
        memcpy(arr1, arr, Len * sizeof(T));
        delete arr;
        arr = arr1;
        Len += size;
        return *this;
    }
    ArrTest& append(ArrTest& brr)
    {
        T* arr1 = new T[Len + brr.length()];  // 확장된 메모리
        memcpy(arr1, arr, Len * sizeof(T));
        memcpy(arr1 + Len, brr.arr, brr.length() * sizeof(T));
        delete arr;
        arr = arr1;
        Len += brr.length();
        return *this;
    }
    /*ArrTest<T> operator+(ArrTest<T>& other1, ArrTest<T>& other2)
    {
        ArrTest<T> result(other1.length() + other2.length());
        memcpy(result.arr, other1.arr, other1.length() * sizeof(T));
        memcpy(result.arr + other1.length(), other2.arr, other2.length() * sizeof(T));
        return result;
    }*/
    ArrTest operator+(ArrTest& other)
    {
        ArrTest result(Len + other.length());
        memcpy(result.arr, arr, Len * sizeof(T));
        memcpy(result.arr + Len, other.arr, other.length() * sizeof(T));
        return result;
    }

    ArrTest<T>& operator+=(ArrTest<T>& other)
    {
        return this->append(other);
    }
    bool operator==(ArrTest<T>& other)
    {
        if (Len != other.Len)
            return false;

        for (int i = 0; i < Len; ++i)
        {
            if (arr[i] != other.arr[i])
                return false;
        }

        return true;
    }

    friend ostream& operator<<(ostream& os, ArrTest& ar)
    {
        int i;
        printf("{");
        for (i = 0; i < ar.Len - 1; i++)
            std::cout << ar.arr[i] << ",";    cout << ar.arr[i];
        printf(" }\n");
        return os;
    }
};
//void ArrTest<T>::show()   // { 1 2 3 4 5} ==> { 1,2,3,4,5 }
//ArrTest& ArrTest::append(int size)  // size :  total ?  
//ArrTest& ArrTest::append(ArrTest& brr)  // size :  total ?  

class Func
{
public:
    int operator()(int a, int b)
    {
        return a * b;
    }
    double operator()(double a, double b)
    {
        return a * b;
    }
    ArrTest<int>& operator()(ArrTest<int>& b1, ArrTest<int>& b2)  // size :  total ?  
    {
        return b1.append(b2);
    }
    ArrTest<double>& operator()(ArrTest<double>& b1, ArrTest<double>& b2)  // size :  total ?  
    {   
        return b1.append(b2);
    }
};
//int func(int arg) {}
int main()
{
    double a1[] = { 15.1, 12.1, 13.1, 11.1, 14.1 };
    ArrTest<double> arr(5);
    for (int i = 0; i < 5; i++)             arr[i] = a1[i];
    //for (int i = 0; i < arr.length() ; i++) printf("ArrTest[%d] = %d\n", i, arr[i]);
    //
    double a2[] = { 21.1, 22.1, 23.1, 24.1, 25.1 };
    ArrTest<double> brr(5);
    for (int i = 0; i < 5; i++)             brr[i] = a2[i];
    //for (int i = 0; i < brr.length() ; i++) printf("ArrTest[%d] = %d\n", i, brr[i]);
    //
    //int n = arr.length();
    //printf("배열 확장 %d --> %d\n\n", n, arr.append(brr).length());
    //
    //for (int i = 0; i < arr.length() ; i++) printf("ArrTest[%d] = %d\n", i, arr[i]);
    Func mul;
    std::cout << mul(2, 3) << "\n";
    std::cout << mul(2.5, 3.7) << "\n";
    //mul(arr, brr).show();

    arr += brr;
    arr.show();
    //arr == brr;
    ArrTest<double> crr = arr + brr;
    //crr.show();
    cout << (arr += brr) << "\n";
    cout << (crr) << "\n";
    cout << (arr += brr) << "\n";
    //cout << (arr == arr ? "Equal" : "Not Equal") << endl;
    if (arr == arr)printf("Same sequence . . . . .\n");

    string s = "안녕하세요";
    cout << s << endl;
    cout << s.substr(2, 2) << endl;
}