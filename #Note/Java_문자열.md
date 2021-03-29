# 📝 문자열(String) 다루기



### 💬 선언 및 정의

```java
String str;
str = "abc";

String str = "abc";

String str = new String("abc");

String str = new String();
str = "abc";
```



### 💬 length: 문자열의 길이

```java
String str = "abc";
int len = str.length();	// len == 3
```

- 해당 객체의 문자열 길이를 반환 (Integer형))
- 단, null은 포함하지 않음 (NullPointerException 발생)



### 💬 isEmpty: 문자열이 비어있는지 확인

```java
String str = new String();
boolean result = str.isEmpty();	// result == true
```

- 문자열의 길이가 0이면 true, 0이 아니면 false를 반환 (Boolean형)



### 💬 charAt: 문자 반환

```java
String str = new String("abcde");
char ch = str.charAt(3);	// ch == 'd'
```

- 문자열 중 해당 인덱스의 문자를 반환 (char형)



### 💬 getChars: 문자 배열 복사

```java
String str = new String("abcde");
char[] ch = new char[4];
str.getChars(0, 2, ch, 0);	// ch == "ab  "
```

- String을 char배열로 복사
- 문자열.getChars(시작, 끝, 배열, 배열 시작)



### 💬 equals: 문자열 비교

```java
String str1 = new String("abcd");
String str2 = new String("abc");
boolean res = str1.equals(str2);	// res == false
```

- 해당 문자열과 매개변수의 문자열이 같으면 true, 다르면 false를 반환(Boolean형)
- 📌 자바에서 문자열 비교를 == 연산자로 할 수 없음



### 💬 compareTo: 문자열 비교 (사전 순으로 대소 비교)

```java
String str1 = new String("aaa");
String str2 = new String("bbb");
int res = str1.compareTo(str2);	// res == -1
```

- 문자열이 매개변수보다 앞인 경우 -1, 같은 경우 0, 뒤인 경우 1을 반환 (Integer형)



### 💬 indexOf: 문자열 위치

```java
String str = new String("abcde");
int idx = str.indexOf("cd");	// idx == 2
```

- 해당 문자열이 위치하는 인덱스를, 존재하지 않으면 -1을 반환 (Integer형)
- 가장 먼저 나오는 위치의 인데스만 반환



### 💬 lastIndexOf: 문자열 위치

```java
String str = new String("abcdecde");
int idx = str.lastIndexOf("cd");	// idx == 5
```

- 해당 문자열이 위치하는 인덱스를, 존재하지 않으면 -1을 반환 (Integer형)
- 가장 마지막에 나오는 위치의 인데스만 반환



### 💬 subString: 문자열 자르기

```java
String str = new String("abcdefghi");
String subStr1 = str.substring(2, 6);	// subStr1 == "cdef"
String subStr2 = str.substring(3);		// subStr2 == "defghi"
```

- 해당 문자열의 인덱스만큼 잘라서 반환 (String 형)
- 매개변수가 2개인 경우 해당 범위만큼 잘라서 반환
- 매개변수가 1개인 경우 해당 인덱스부터 나머지 반환



### 💬 concat: 문자열 합치기

```java
String str1 = new String("abc");
String str2 = new String("def");
String res = new String();

str1.concat(str2);	// res == "abcdef"
res = str1 + str2;	// res == "abcdef"
```

- 해당 문자열 뒤에 매개변수 문자열을 서로 합침
- 문자열 + 문자열로 같은 결과를 얻을 수 있음



### 💬 replace: 문자열 치환

```java
String str = new String("abcaaa");
str = str.replace('a', 'z');	// str == "zbczzz"
```

- 해당 문자를 찾아 다음 문자로 변경



### 💬 contains: 문자열 포함

```java
String str = new String("abc");
boolean res1 = str.contains("bc");	// res1 == true
boolean res2 = str.contains("cd");	// res2 == false
```

- 해당 문자열이 포함되어 있는지 확인
- 포함할 경우 true, 아닌 경우 false를 반환(Boolean형)



### 💬 split: 문자열 분리

```java
String str = new String("a,b,c,d,e");
String[] str2 = new String[5];

for (int i = 0; i < 5; i++) str2[i] = str.split(",")[i];
for (int i = 0; i < 5; i++) System.out.print(str2[i]);	// abcde 출력
```

- 문자열을 해당 문자열을 기준으로 모두 분리 (String[] 반환)



### 💬 trim: 문자열 공백 제거

```java
String str = new String(" a b c ");
String res = str.trim();	// res == "a b c"
```

- 해당 문자열의 앞, 뒤의 공백을 모두 제거
- 단, 문자열 사이의 공백은 제거되지 않음





------

**🔎 참고 문서**

- [자바 String 문자열 사용법 정리](https://yeolco.tistory.com/30)



