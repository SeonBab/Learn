# 클래스(Class)

일상에서의 객체를 프로그램 코드로 표현하기 위한 사용자 정의 자료형이다. C++ 언어의 객체는 자신만의 고유한 상태(state) 정보를 저장하고 있는 멤버 변수(속성)와 객체의 행동(behavior)에 해당하는 멤버 함수(기능)로 구성된다. 행동으로 객체의 상태가 변화하거나 객체의 상태가 외부로 전달되기도 한다.

클래스는 C의 구조체에서 확장된 C++ 구조체의 또다른 이름이라고 볼 수 도 있다. 클래스는 함수를 포함 할 수 있으며, 기본 접근 제한자에 차이가 있을 뿐 거의 같다. \
클래스와 구조체가 동일한 기능을 하면서 존재하는 이유는 C++에서 C와의 하위 호환성을 위해 남겨졌다고 볼 수 있다.


# 클래스 선언과 정의

```
class 클래스이름 // 클래스 이름의 자료형을 정의
{
    접근지정자:
    멤버 변수 선언1; // 객체의 상태 또는 특성에 해당하는 변수 "자료형 변수이름"의 형태로 선언
    멤버 변수 선언2;
    ...

    멤버 함수 선언1; // 객체의 기능에 해당하는 함수 "반환자료형 함수이름(인수 리스트)"의 형태로 선언
}; // 세미콜론(;)으로 끝내야한다.

class Rect
{
    public:
    int width;      // 멤버 변수 선언
    int height;

    int getArea();  // 멤버 함수 선언
};
```

멤버 함수의 경우 클래스 정의 내 정의되거나 클래스 정의 밖에서 정의할 수 있다.멤버 함수를 클래스 정의 밖에서 정의하는 구문은 다음과 같다.

```
반환자료형 클래스이름::함수이름(인수리스트) // 멤버 함수 정의
{
    ...
}

int Rect::getArea()
{
    return width * height;
}
```

클래서 정의 영역 내부에서 getArea() 함수의 정의는 다음과 같다.
```
class Rect
{
    public:
    int width, height;
    int getArea() { return width * height; }  // 멤버 함수 정의
};
```

멤버 함수를 클래스 정의 영역 내부에 정의할 경우 간결해 보일 수 있으나 멤버 함수의 개수가 많은 경우 클래스의 전체 구조를 한 눈에 파악하기 어렵다. 그러므로 가능하면 클래스의 정의와 멤버 함수의 정의를 분리하여 표현하는 것이 일반적이다.

클래스의 멤버 변수와 멤버 함수는 멤버 선택 연산자(.)를 사용해 접근 할 수 있다.

# 접근지정자(Access specifiers)

C++의 접근 지정자는 private, protected, public의 세 가지 접근 지정 키워드가 있다. 이 접근지정자는 C++의 데이터 캡슐화와 관련이 있다.

private 접근 지정자를 갖는 멤버 변수, 멤버 함수는 클래스 외부에서 접근이 불가능한 것으로 클래스 내부의 멤버 함수에 의해서만 접근이 가능하다.

클래스는 기본적으로 모든 멤버 변수와 멤버 함수는 private 접근 지정자를 가진다.

```
#include <iostream>
using namespace std;

class Rect
{
  int width;    // private 멤버 변수
private:
  int height;   // private 멤버 변수 

public:
  Rect(int w = 2, int h = 2) : width(w), height(h)  // public 멤버 함수
  int getArea() { return width * height; }          // public 멤버 함수
};
 
int main()
{
  Rect rectangle;
  rectangle.width = 5;  // 접근 오류
  rectangle.height = 4; // 접근 오류
  
  cout << "Width: " << rectangle.width<< endl;  // 접근 오류
  cout << "Area: " << rectangle.getArea() << endl; 

  return 0;
}
```

컴파일하면 다음과 같이 세 곳에서 에러가 발생한다.

```
error: 'width' is a private member of 'Rect'
  rectangle.width = 5;                          // 접근 오류
            ^
error: 'height' is a private member of 'Rect'
  rectangle.height = 4;                         // 접근 오류
            ^
error: 'width' is a private member of 'Rect'
  cout << "Width: " << rectangle.width<< endl;  // 접근 오류
```

반면 public은 접근 지정자를 갖는 멤버 변수와 멤버 함수는 클래스 외부에서 접근이 가능하다.

그렇기에 위에 예시에서 `cout << "Area: " << rectangle.getArea() << endl;`는 컴파일 에러가 발생하지 않고 멤버 함수에 접근이 가능하다.

protected는 private 접근 지정자와 비슷하게 클래스 외부에서는 protected 멤버에 접근하지 못하나 상속을 받는 자식 클래스 내부의 멤버들은 접근이 가능하다. 이 접근 지정자는 상속 관계에서만 의미를 가진다. \
private 접근 지정자로 지정된 멤버는 상속 받은 자식 클래스 내부에서도 접근이 불가능하다.

```
class Shape
{
protected:
  int pointX, pointY;   // protected 멤버 변수

public:
  Shape(int x = 2, int y = 2) : pointX(x), pointY(y) {}
  void printPoint() { cout <<"point: " << pointX << ", " << pointY << endl; } 
};
 
class Rect : public Shape     // Shape 클래스를 상속받는 Rect 클래스 
{
private:
    int width, height;

public:
 	Rect(int w, int h) : width(w), height(h) {}
 	void printEndpoint()
  {
 		cout <<"Rect: " << pointX + width << ", " << pointY + height << endl;
 	}
};
```

부모 클래스의 pointX, pointY 멤버 변수가 protected 접근 지정자로 지정되어 있으므로 상속받은 Rect 클래스의 멤버 함수에서 접근 할 수 있다.

# 생성자(Constructor)

클래스에는 인스턴트화 될 때 자동으로 호출되는 생성자라는 특수한 멤버 함수를 가진다. \
일반적으로 생성자를 통해 클래스가 사용되기 전에 수행하여야 할 기능 예로 멤버 변수 초기화, 동적 메모리 할당 등을 수행한다.

생성자는 다음과 같은 특징을 가진다.

+ 생성자는 함수이다.
+ 클래스가 인스턴스화 될 때 반드시 하나의 생성자가 호출되어야 한다.
+ 생성자는 클래스가 인스턴스화 될 때 호출되는 함수로 객체가 생성될 때 필요한 초기 작업을 한다.
+ 클래스 인스턴스화 시 생성자는 오직 한번만 자동으로 실행한다.
+ 일반 멤버 함수인 것처럼 명시적으로 호출 할 수 없다.
+ 생성자의 이름은 클래스 이름과 동일해야한다.
+ 아무것도 리턴하지 않으며 void도 아니다.
+ 오버로딩이 가능해 한 클래스에서 여러개의 생성자를 만들 수 있다.
+ 함수이므로 디폴트 매개변수를 가질 수 있다.
+ 선언되지 않으면 컴파일러가 inline 기본 생성자(default constructor)를 자동으로 생성한다.
+ 매개변수가 있는 생성자를 선언하는 경우 컴파일러는 기본 생성자를 자동으로 생성하지 않는다.

생성자는 클래스 정의 또는 상속 계층 구조의 외부의 코드가 클래스의 객체를 만들 수 있도록 일반적으로 public 접근성을 가지나 private 또는 protected 접근성을 가지도록 선언할 수 있다.

정의하는 구문은 다음과 같다.
```
class이름::class이름(인수 목록)
{
  ....
}

class Rect
{
  Rect();             // 기본 생성자
  Rect(int w);        // 생성자 오버로드 (매개변수 한 개)
  Rect(int w, int h); // 생성자 오버로드 (매개변수 두 개)
  ...
};
```

### 기본 생성자(default constructor)

기본 생성자는 매개 변수가 없는 생성자를 말한다. 다만, 매개 변수만 없을 뿐 수동으로 기능을 구현 할 수 있다. \
생성자가 하나도 선언되지 않은 클래스의 경우 컴파일러가 기본 생성자를 자동으로 생성한다. 컴파일러가 생성한 기본 생성자는 아무 코드도 실행되지 않고 바로 리턴한다. \
인스턴스화 시 초기값을 제공하지 않으면 기본 생성자가 호출된다.


```
#include <iostream>
using namespace std;

class Person
{
private:
  string name;
  int age;

public:
  void setName(string n) { name = n;}
  void setAge(int a) { age = a;}
  void show()
  {
    cout << name << ", " << age << endl;
  }
};

int main()
{
   Person s;  // 컴파일러가 자동 생성한 기본 생성자 Person() 호출 
   s.setName("Seonguk Kim");
   s.setAge(25);
   s.show();

   return 0;
}
```

실행 결과는 다음과 같다. `Seonguk Kim, 25`

앞의 코드의 main 함수를 다음과 같이 수정하여 얻은 실행 파일을 실행하였을 때 결과를 생각해보자

```
int main()
{
	Person man;
	man.show();

	return 0;
}
```

결과의 값은 임의의 값이 출력될 것이다. 클래스가 인스턴스화 되고 데이터를 저장할 수 있는 메모리 저장 공간이 할당 되었으나 저장 공간이 초기화 되지 않아 쓰레기 값을 가지고 있기에 나온 결과이다.

컴파일러가 기본 생성자를 생성하지 못하도록 다음과 같이 `person() = delete;`로 컴파일러에서 생성된 기본 생성자를 삭제되도록 명시적으로 정의 할 수 있다.

```
class Person
{
private:
   string name;
   int age;

public:
   Person() = delete; // 컴파일러의 기본 생성자 생성을 하지 않도록 함 
   void setName(string n) { name = n;}
   void setAge(int a) { age = a;}
   void show()
   {
      cout << name << ", " << age << endl;
   }
};

int main()
{
	Person man;
	man.show();

	return 0;
}
```

하지만 위와 같은 경우에선 기본 생성자를 생성하지 않았고, main 함수에서 클래스를 기본 생성자를 활용해 인스턴스화 하려 하므로 에러가 날 것 이다.
