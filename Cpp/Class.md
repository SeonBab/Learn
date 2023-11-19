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
class Rect
{
  int width;    // private 멤버 변수
private:
  int height;   // private 멤버 변수 

public:
  Rect(int w = 2, int h = 2) : width(w), height(h) {} // public 멤버 함수
  int getArea() { return width * height; }            // public 멤버 함수
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

### 기본 생성자(Default Constructor)

기본 생성자는 매개 변수가 없는 생성자를 말한다. 다만, 매개 변수만 없을 뿐 수동으로 기능을 구현 할 수 있다. \
생성자가 하나도 선언되지 않은 클래스의 경우 컴파일러가 기본 생성자를 자동으로 생성한다. 컴파일러가 생성한 기본 생성자는 아무 코드도 실행되지 않고 바로 리턴한다. \
인스턴스화 시 초기값을 제공하지 않으면 기본 생성자가 호출된다.

```
#include <iostream>
using namespace std;

class Person
{
public:
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

기본 생성자를 다음과 같이 수동으로 사용 할 수 있다.

```
class Person
{
public:
  string name;
  int age;

public:
  Person()  // 기본 생성자
  {
    name = "Seonguk Kim";
    age = 25;
  }
};
```

사용자가 정의한 기본 생성자가 호출되고 정의된 기본 생성자에 따라 값이 할당 됐다. 그렇기에 다음과 같은 실행 결과가 나올 것이다. `Seonguk Kim, 25`

혹은 다음과 같은 방법으로 기본 생성자에서 하나 혹은 두 개의 사용자 제공 값을 허용할 수 있다.

```
class Person
{
public:
  string name;
  int age;

public:
  Person(string str = "Seonguk Kim", int num = 25)  // 기본 생성자
  {
    name = str;
    age = num;
  }
};
```

컴파일러가 기본 생성자를 생성하지 못하도록 다음과 같이 `person() = delete;`로 컴파일러에서 생성된 기본 생성자를 삭제되도록 명시적으로 정의 할 수 있다.

```
class Person
{
public:
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

하지만 위의 경우에선 기본 생성자를 생성하지 않았고, main 함수에서 클래스를 기본 생성자를 활용해 인스턴스화 하려 하므로 에러가 날 것이다.

### 멤버 초기화 리스트(Constructor Member Initializer List)

멤버 초기화 리스트는 객체의 생성 후 값을 대입하는 것이 아닌, 객체의 생성과 동시에 값을 지정할 수 있게 한다. 이 방법은 direct initialization이나 uniform initialization으로 초기화 하는 것과 거의 동일하다.

초기화 리스트가 멤버 변수 초기화 기능을 대체하므로 더는 생성자 본문에서 수행할 필요가 없어진다.

const 또는 reference 변수와 같이 초기값이 필요한 멤버를 초기화할 수 있는 유일한 방법이다.

```
Person(string n, int a) : name {n}, age {a} {}
```

# 복사 생성자 (Copy Constructor)

복사 생성자는 동일한 자료형의 객체가 가진 멤버 변수의 값을 복사하여 객체를 초기화 한다. 즉 선언되는 객체와 같은 자료형을 가진 객체의 복사가 필요할 때 사용되는 생성자이다. \
클래스의 멤버 변수가 값을 저장하는 간단한 형태라면 컴파일러에서 생성하는 디폴트 복사 생성자(default copy constructor)로 충분하여 사용자가 직접 복사 생성자를 정의할 필요는 없으나 객체 복사 시 복잡한 초기화가 필요한 경우 사용자 정의 복사 생성자를 정의하여야 한다.

복사 생성자를 정의하는 구문은 다음 중 하나이다.
```
<클래스 이름>(<클래스 이름>& <변수 이름>);
<클래스 이름>(const <클래스 이름>& <변수 이름>);
<클래스 이름>(volatile <클래스 이름>& <변수 이름>);
<클래스 이름>(volatile const <클래스 이름>& <변수 이름>);

<클래스 이름>(<클래스 이름>& <변수 이름>, ...기본 값들...);
```

입력 파라미터의 `const` 키워드는 복사하려는 원본의 값을 함수 내에서 변경시키지 않도록 한다. \
`volatile`키워드는 사용하여 선언된 변수는 프로그램 실행 중 외부적인 요인으로 메모리에 저장된 값이 언제든 바뀔 수 있는 변수라는 것으로 컴파일러에게 알리기 위한 키워드이다. 컴파일러는 `volatile`로 선언된 변수에 대해서 최적화하지 않는다. `volatile` 변수를 참조할 경우 CPU레지스터에 로드된 값을 사용하지 않고 매번 메모리를 참조한다. 

+ MMIO(Memory-mapped I/O): I/O 디바이스가 메모리 주소에 매핑된 I/O
+ 인터럽트 서비스 루틴 사용
+ 멀티 스레드 환경

인터럽트 서비스 루틴과 멀티 스레드 프로그램 작성 시 서로 공유해야 하는 전역 변수의 경우 컴파일러가 코드를 최적화하지 않고 순차적으로 모두 수행하도록 하여야 하는 경우 `volatile`을 사용한다.

```
#include <iostream>
using namespace std;

class Person
{
public:
  string name;
  int age;

public:
  Person(string name, int age)  // 생성자
  {
    this->name = name;
    this->age = age;
  }

  Person(const Person &other) // 복사 생성자
  {
    cout << "User defined Copy constructor" << endl;     
    name = other.name;
    age = other.age;
  }

  void show()
  {
    cout << name << ", " << age << endl;
  }
};
```

클래스는 어떻게 복사하느냐에 따라 얕은 복사와 깊은 복사로 나뉜다.

얕은 복사(shallow copy)란 객체가 가진 멤버들의 값을 새로운 객체로 복사할 때 객체가 가진 참조자(reference)와 값(value)모두 똑같이 가지게 된다. 즉 HEAP에 할당된 멤버의 주소 값이 복사되며, 동일한 주소를 참조하는 새로운 멤버가 만들어진다. \
동일한 주소값을 가진 새로운 멤버가 만들어지며 문제가 생길 수 있게 되는데, 하나의 객체에 멤버 변수 값만 변경해도 다른 객체의 멤버 변수 값이 변경되며 한 객체가 소멸하면서 메모리를 해제한다면 다른 객체의 멤버는 댕글링 포인터가 될 수 있어 문제가 될 수 있다.

디폴트 복사 생성자는 얕은 복사를 수행한다.

깊은 복사(deep copy)는 참조변수의 경우 새로운 객체를 만들어 할당하는 방식으로 복사한다. \
참조변수에 저장된 값인 주소값을 복사하는 것이 아닌 참조변수가 참조하는 값을 복사하여 새로운 변수를 동적할당 해주어야한다. \
참조변수가 아닌 멤버 변수는 얕은 복사와 동일하다.

깊은 복사가 자원을 더 많이 소모하고, 메모리를 실제 복사한다.

복사 생성자는 다음과 같은 시점에서 호출된다.

+ 기존에 생성된 객체를 이용해 새로운 객체를 초기화 할 때
+ Call-by-Value 방식으로 함수 호출을 진행할 때
+ 객체를 반환 할 때 참조형으로 반환하지 않는 경우 [임시 객체]

2번째 경우인 인자 전달에 의한 복사 생성자 호출의 경우 함수의 매개변수 객체의 복사 생성자가 호출된 뒤 복사 생성자의 인자가 함수에 인자로 전달되 객체가 사용된다.

3번째 경우인 반환에 의한 복사 생성자 호출의 경우 객체를 반환하면 임시 객체가 생성되며, 임시 객체 생성을 위해 복사생성자가 호출된다. 복사생성자의 인자로 반환된 객체가 사용되며 객체가 반환된 동시에 함수 호출이 종료되기에 지역적으로 선언된 객체는 소멸된다.

임시객체를 소멸되지 않게 하고자 한다면 생성된 위치에 임시객체의 참조 값이 반환되는 것을 이용해야 한다. \
객체를 저장하지 않더라도 반환된 위치에 존재하는 참조값을 참조자가 참조하면 객체가 소멸하지 않는다.

### 이동 생성자(Move Constructor)

C++11에 Rvalue reference를 파라미터로 가지는 새로운 타입의 생성자가 추가되었다. 함수 호출 시 임시 개체(rvalue)에 대한 복사가 너무 많이 일어나 해결하기 위해 추가됐다.
이동 생성자는 얕은 복사를 하고, 기존 객체의 데이터 소유권을 새 변수에 이동하는 멤버 함수다. 이 과정에서 원본 객체는 NULL로 초기화해 접근할 수 없게 만든다.\

명시적 또는 암시적 이동 생성자가 정의되어 있지 않으면 이동 생성자를 사용하는 작업은 복사 생성자를 대신 사용한다. \ 
클래스가 이동 생성자 또는 이동 할당 연산자를 선언한 경우 암시적으로 선언된 복사 생성자는 삭제된 것으로 정의한다.

이동 생성자는 다음과 같은 상황에 호출된다.
+ 함수의 반환 값이 전달 될 때
+ 저장 공간의 소유권을 이동시키고자 할 때

이동 생성자의 구문은 다음과 같다.

```
<클래스 이름>(<클래스 이름>&& <변수 이름>);

Person(Person&& other);
```

```
class Person
{
public:
  string name;
  int age;
  float* weight;

public:
  Person(Person&& other); // 이동 생성자
}

Person::Person(Person&& other) : name {std::move(other.name)}, age {other.age}, weight {other.weight}
{
    other.name = "";
    other.age = 0;
    other.weight = nullptr;
}
```

### 묵시적 변환

```
int main()
{
  Person kim {"Seon-guk Kim", 25};
  
  Person man = kim; // 복사 생성자 호출 (man 객체는 kim 객체의 내용을 복사하여 생성)

  return 0;
}
```

위의 코드 중 `person man = kim;`코드는 `person man(kim)`로 묵시적 변환이 되어 `kim`객체를 매개변수로 받을 수 있는 복사 생성자가 호출되어 `man`객체가 생성된다.\
만약 자동으로 묵시적 변환이 되어 객체가 생성되는 것을 막으려 한다면 `explicit`키워드가 사용된다. 복사 생성자 앞에 `explicit`키워드를 적어주면 대입연산자를 이용하여 복사 생성자 호출 및 초기화가 불가능하여 묵시적 변환을 막을 수 있다.

```
explicit Person(const Person &other)  // 복사 생성자
{    
  name = other.name;
  age = other.age;
}
```

다음과 같이 복사 생성자를 삭제된 것으로 정의해 객체가 복사되지 않도록 할 수 있다.

```
person(const person &other) = delete;
```


# 소멸자

객체가 소멸되면 객체에 할당된 메모리는 반환된다. 소멸자는 객체가 소멸되는 시점에 반드시 자동으로 호출되는 클래스의 멤버 함수이다.

클래스의 멤버 변수들이 단순하게 기본 자료형이 값 형식이라면 크게 필요 없지만 다른 리소스(동적 메모리, 파일 또는 데이터베이스 핸들러)라면 객체가 소멸되기 전에 어떤 종류의 유지보수를 해야하며, 이때 소멸자는 객체가 소멸되기 전 마지막으로 호출되는 함수이므로 완벽한장소가 된다.

+ 소멸자는 함수이다.
+ 소멸자는 객체가 사라질 때 필요한 마무리 작업을 하게 된다.
+ 소멸자의 이름은 클래스 이름 앞에 ~를 붙인다.
+ 소멸자는 반환 자료형이 없으며 아무것도 반환하지 않는다.
+ 오직 한개만 존재하고 매개 변수는 가질 수 없다.
+ 소멸자가 선언되어 있지 않으면 컴파일러가 기본 소멸자(default destructor)를 자동으로 생성한다.

```
class이름::~class이름(인수 목록)
{
  ....
}

class Rect
{
public:
  int width, height;

public:
  Rect(int w = 1, int h = 2) : width {w}, height {h} {}
  ~Rect();
  int getArea() { return width * height; }  // 멤버 함수 정의
};

Rect::~Rect()
{
  cout << "소멸자 호출" << endl;
}

int main()
{
  Rect s;  // 컴파일러가 자동 생성한 기본 생성자 호출 
  
  int Area = s.getArea();

  return 0;
}
```

`main`함수에서 `int Area`가 복사 초기화 된 후 `main`함수가 종료되면서 객체 `s`의 소멸자가 호출된다.