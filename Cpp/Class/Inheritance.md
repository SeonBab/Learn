# 상속(Inheritance)

상속을 통해 기존 클래스에서 새 클레스를 파생할 수 있다. \
파생에 사용되는 클래스를 특정 파생 클래스의 기본, 부모, 상위 클래스 라고 한다. \
파생 클래스는 자식, 하위, 유도, 서브 클래스라고 부른다. \

상속은 ia-a관계가 있는 경우에만 상속을 한다.

장점으로 다음과 같다.
+ 코드의 중복 작성을 없애 클래스를 간결하게 구현 할 수 있게된다.
+ 관련 클래스를 계층 관계로 표현함으로서 클래스들의 구조적인 관계 파악을 쉽게 해준다.

파생 클래스는 다음 구문을 사용하여 선언된다.

```
class 클래스이름 : [접근지정자] 부모클래스이름
{
    멤버 리스트
    ...
}
```
```
class PrintedDocument {};

class Book : public PrintedDocument {};

class PaperbackBook : public Book {};
```

그림으로 다음과 같이 상속하고 있는데, 이는 단일 상속이다.

![single_inheritance](https://learn.microsoft.com/ko-kr/cpp/cpp/media/vc38xj1.gif?view=msvc-170)

위의 경우 `Book`이 `PrintedDocument`에서 파생 클래스인 동시에 기본 클래스다.

`Book`은 일종의 `PrintedDocument`이고, `PaperbackBook`은 일종의`Book`이다. \
`PrintedDocument`는 `Book`의 "직접 기본" 클래스로 간주되며 `PaperbackBook`의 "간접 기본" 클래스다. 이 두 클래스 간의 차이점으로 직접 기본 클래스는 클래스 선언의 기본 목록에 표시되지만 간접 기본 클래스는 표시되지 않는다.

각 클래스가 파생되는 기본 클래스는 파생 클래스의 선언 이전에 선언되어야 한다. 기본 클래스에 대한 전방 참조 선언만을 제공하는 것으로는 부족하고, 완전한 선언을 제공해야 한다.

상속을 받고, 파생 클래스는 기본 클래스의 멤버와 새로 추가하는 멤버를 포함한다. 따라서 파생 클래스는 기본 클래스의 멤버를 참조 할 수 있다. \
기본 클래스의 멤버를 참조 할 때 멤버의 접근 지정자에 영향을 받지만 상속 시 정한 클래스의 접근 지정자에 영향을 받기도 한다. \
멤버 접근 지정자와 상속 접근 지정자의 경우 제한이 더 높은 지정자로 변경된다. \
예로는 다음과 같다.

<table>
    <tr>
        <td>상속 접근 지정자</td>
        <td>기본 클래스</td>
        <td>파생 클래스</td>
    </tr>
    <tr>
        <td rowspan="3">public</td>
        <td>public</td>
        <td>public</td>
    </tr>
    <tr>
        <td>protected</td>
        <td>protected</td>
    </tr>
    <tr>
        <td>private</td>
        <td>private</td>
    </tr>
        <tr>
        <td rowspan="3">protected</td>
        <td>public</td>
        <td>protected</td>
    </tr>
    <tr>
        <td>protected</td>
        <td>protected</td>
    </tr>
    <tr>
        <td>private</td>
        <td>private</td>
    </tr>
        </tr>
        <tr>
        <td rowspan="3">private</td>
        <td>public</td>
        <td>private</td>
    </tr>
    <tr>
        <td>protected</td>
        <td>private</td>
    </tr>
    <tr>
        <td>private</td>
        <td>private</td>
    </tr>
</table>

### 다중 상속(Multiple Inheritance)

다중 상속은 말 그대로 둘 이상의 클래스를 동시에 상속하는 것을 말한다. \
즉 하나의 파생 클래스가 두 개 이상의 기본 클래스를 가지고 상속하는 것을 말한다.

다음 구문을 사용하여 선언된다.

```
class 클래스이름 : [접근지정자] 부모클래스이름, [접근지정자] 부모클래스이름, ...
{
    멤버 리스트
    ...
}
```
```
class Queue {};

class CashierQueue : public Queue {};

class LunchQueue : public Queue {};

class LunchCashierQueue : public CashierQueue, public LunchQueue {};
```

![multiple_inheritance](https://learn.microsoft.com/ko-kr/cpp/cpp/media/vc38xp1.gif?view=msvc-170)

`CashierQueue`와 `LunchQueue`는 `Queue`의 파생 클래스다. 이 파생 클래스들이 기본 클래스가 되어 하나의 파생 클래스인 `LunchCashierQueue`를 형성한다.

다중 상속은 이해해야하고 꼭 필요한 경우 사용해야하는데 다중 상속에는 문제점이 존재한다. \
예를 들면 각각의 다른 기본 클래스에 같은 이름의 함수가 있다면 어느 함수를 호출할지 모르는 모호성이 발생합니다. 이 경우 범위 지정 연산자로 해결 할 수 있다. \
다이아몬드 상속 즉 위와 같은 이미지 일 때 `Queue`가 두번 상속되는 문제가 있다. 이 경우 가상 상속을 통해 해결 할 수 있다.

다중 상속은 객체가 생성 될 때 상속 받은 기본 클래스의 생성자를 각각 하나씩 호출한다.

### 가상 상속 (Virtual Inheritance)

위와 같은 다이아몬드 상속의 구조같은 경우 멤버의 중복과 생성자의 호출로 메모리 낭비를 가져올 수 있다. 이런 경우가 꼭 다이아몬드 구조에서만 발생하는 것은 아니며, 다중 상속에선 충분히 발생 할 수 있는 문제다. 이런 모호성 문제와 메모리 낭비를 해결 할 수 있는 방법이 바로 가상 상속이다.

가상 상속은 다음과 같은 방법으로 사용한다.
```
class 클래스이름 : [접근지정자] 부모클래스이름
{
    멤버 리스트
    ...
}
```

```
class Queue {};

class CashierQueue : virtual public Queue {};

class LunchQueue : virtual public Queue {};

class LunchCashierQueue : public CashierQueue, public LunchQueue {};
```

`Queue`를 상속 받을 때 `virtual` 키워드를 추가한 것이다. \
이와 같은 방법으로 상속을 할 경우 기본 클래스를 가상 기본 클래스(Virtual Base Class)라고 한다. \
가상 기본 클래스는 여러 번 상속되더라도 메모리 구조상 하나만 존재하게 되고, 모호성 문제로 인한 컴파일 에러가 발생하지 않게 된다. \
그러나 클래스에 `virtual` 키워드를 적용 한 것 과 적용하지 않은 파생 클래스 2개를 상속 받는다면 가상 기본 클래스와 기본 클래스로 메모리가 각각 생성된다. 그러므로 중복 제거의 효과가 사라진다.

가상 상속된 가상 기본 클래스는 생성자가 여러번 호출 되지 않고 한번만 호출하게된다. \
예로 위의 경우 `Queue`가 가상 기본 클래스가 아니라면 `CashierQueue`와 `LunchQueue`의 생성자가 호출 될 때 마다 호출되어야 하므로 `Queue`가 두번 호출되어야 한다. 하지만 가상 기본 클래스이므로 한번만 호출한다.
가상 기본 클래스의 생성자가 최종 클래스의 생성자에서 호출 될 경우 중간 기본 클래스의 생성자에서 가상 기본 클래스의 생성자를 호출하지 않는다.

메모리 구조는 컴파일러마다 다르지만 Visual C++ 컴파일러를 기준으로 중간 기본 클래스는 가상 기본 클래스를 관리하기 위해 메모리 시작 부분에 기본 포인터 크기(x86 4바이트, x64 8바이트)만큼 메모리 영역을 확보한다. \
위의 예시로는 중간 기본 클래스 2개가 각각 메모리를 할당받아 클래스의 크기가 더 커진다. 이와 같은 경우로 작은 크기의 클래스를 가상 기본 클래스로 만들 경우 메모리 절약 효과가 그리 크지 않을 수 있다. 그러므로 중복 클래스를 제거해 메모리 절약 효과가 있을 정도로 크기가 커야 의미가 있다.

메모리 절약 효과가 크다해서 바로 사용 할 수 없다. 이유는 다음과 같은데 클래스의 멤버 함수를 호출하거나 멤버에 접근할 경우 클래스 포인터의 타입 변환이 필요하다. 이때 가상 상속을 사용할 경우 가상 기본 클래스의 주소를 한번 거쳐야 한다. \

이와 같은 이유로 가상 상속을 사용할 경우 신중하게 생각해야하며, 메모리 절약과 성능 중 우선순위를 잘 따져보고 선택해야하고, 사용하지 않는 것이 가장 좋다.

중간 기본 클래스가 가상 기본 클래스를 관리하기 위한 메모리는 가상 테이블(Virtual Table)이라는 특정 테이블을 가르키는 포인터다. \
이 테이블에는 가상 기본 클래스의 오프셋 정보가 포함되어 있고, 최소한 두 개 이상의 항목을 가지게 된다.
오프셋은 특정 위치를 기준으로 얼마나 떨어져있는가를 나타낸 것이다. 즉 클래스의 메모리 시작 주소가 특정 위치를 기준으로 얼마나 떨어져있는지다. 특정 위치의 기준은 가상 테이블의 메모리 위치가 기준이 된다.

### 업캐스팅, 다운캐스팅 (Up Casting, Down Casting)

객체지향에서 캐스팅이란 형변환을 의미한다.

업캐스팅과 다운캐스팅은 상속 관계에 있는 객체에서만 일어난다. \
다형성에 의해 서로의 객체 포인터가 다른 타입의 객체를 가리킬 수 있게 되고, 이를 활용해 코드 재사용성을 높일 수 있다.

업 캐스팅(up casting)은 기본 클래스 포인터가 파생 클래스 객체를 가리키는 것이다.

```
class Base
{
public:
    virtual void print()
    {
        std::cout << "Base" << std::endl;
    }
};

class Derived : public Base
{
public:
    void print()
    {
        std::cout << "Derived" << std::endl;
    }

    void show()
    {
        std::cout << a << std::endl;
    }

private:
    int a = 2;
};

int main()
{
    Derived drv1;

    Base* pBase = &drv1;

    pBase->print();
    pBase->show(); // 오류
}
```

업 캐스팅을 하게되면 기본 클래스에 정의된 멤버만 호출 할 수 있고, 파생 클래스의 기능을 사용할 수 가 없다. \
위의 경우 `Base`클래스에 정의되지 않은 `show()`함수를 호출하려 해 오류가 발생한다. \
오류가 발생한 코드를 지우고, 출력을 확인한다면 다음과 같을 것이다.

```
Derived
```

다운 캐스팅(down casting)은 파생 클래스 포인터가 기본 클래스 객체를 가리키는 것이다. \
업 캐스팅 된 포인터를 원래 형으로 되돌려 주는 작업을 할 수 있다.

```
int main()
{
    Derived drv1;

    Base* pBase = &drv1;

    Derived* pDerived = pBase; // 오류
    Derived* pDerived = (Derived*)pBase;

    pDerived->print();
    pDerived->show();
}
```

다운 캐스팅은 업 캐스팅과 다르게 명시적 형변환을 해야한다. \
위의 경우 `pBase`가 가진 주소값을 이용해 `pDerived`를 초기화려 하는데 암시적 형변환이 되지 않아 오류가 발생한다. \
오류가 발생한 코드를 지우고, 출력을 확인한다면 다음과 같을 것이다.

```
Derived
2
```

기본 클래스를 다운 캐스팅을 하게되면 기본 클래스에 없고 파생 클래스에만 존재하는 멤버들에게 접근하려고 할 때 에러 발생의 위험이 있다.

```
int main()
{
    Base base;

    Derived* pDerived = (Derived*)&base;

    pDerived->print();
    pDerived->show(); // 문제가 될 수 있다.
}
```

위의 경우 `Derived`클래스의 `show()`함수가 호출된다. 호출이 되고 함수가 실행되는 이유는 `Derived`클래스의 함수 주소를 찾아가 호출한 것이기 때문에 함수가 호출된다. \
하지만 함수가 실행되며 `a`라는 변수의 값을 출력하고자 하는데 `a`라는 변수는 `Derived`클래스의 객체만 존재하고, `Base`클래스의 객체에서는 찾을 수 없다. 그렇기에 알 수 없는 값이 출력 될 것이다. \
이렇게 기본 클래스를 다운 캐스팅 하고, 파생 클래스에만 존재하는 멤버에 접근할 때 문제가 될 수 있다.