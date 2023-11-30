# 프렌드(Friend)

클래스의 private 및 protected 멤버는 선언된 클래스 외부에서 액세스 할 수 없지만 프렌드 키워드를 사용해 지정한 대상이 클래스 내의 모든 멤버를 접근 할 수 있도록 권한을 부여해 준다. \
프렌드 키워드는 클래스, 멤버 함수, 전역 함수의 세 가지 형태로 사용할 수 있다.

다른 타입의 객체를 접근하는 것이 가능해져 코드의 확장이 수월해지지만 캡슐화 파괴의 주범이 되어 설계가 꼬여버릴 수 있다. \
객체지향적 설계라고 보기 어렵다.

사용 시 주의사항으로는 다음과 같다.
+ 프렌드의 프렌드는 접근 권한이 없다.
+ 프렌드를 상속 받은 자식은 접근 권한이 없다.

### 프렌드 함수

클래스의 멤버 함수와 같은 접근 권한을 가지는 전역 함수 또는 다른 클래스의 멤버 함수를 프렌즈 함수라 한다.

클래스 선언부에 원형이 포함되지만, 클래스의 멤버 함수는 아니고, 함수의 본체는 따로 정의된다.

프렌드 키워드를 사용한 선언은 다음과 같습니다.

```
// 전역 함수
friend 반환자료형 함수이름(매개변수목록);

// 다른 클래스의 멤버 함수
friend 클래스이름 함수이름(매개변수목록);

class Rect
{
  int width, height;

  friend bool equals(Rect a, Rect b);
}

bool equals(Rect a, Rect b)
{
  return ((a.width == b.width) && (a.height == b.height));
}
```

선언은 클래스 내의 어디에서든 가능하다.

### 프렌드 클래스

프렌드 키워드를 사용한 선언은 다음과 같습니다.

```
friend 클래스이름;

friend class 클래스이름;
```

첫번째 선언은 클래스가 이미 선언되었을 때 사용 할 수 있으며 템플릿 형식 매개변수 또는 typedef friend로 선언할 때 사용해야 한다.

```
// 이미 선언된 클래스를 참조
class RectA {};

class My_ClassA
{
  friend Rect;  
};

// 템플릿 매개 변수를 프렌드로 선언하는 데 사용
template <typename T>
class My_ClassB
{
    friend T; 
};

// typedef를 프렌드로 선언하는 데 사용
class RectB {};
typedef RectB Z;

class My_ClassC
{
    friend Z; // OK
};
```

두번째 선언은 참조된 형식이 이미 선언되어 있지 않은 경우 사용한다.

```
class My_ClassD
{
  friend class Rect;
};
```