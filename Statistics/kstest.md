## Kolmogorov Smirnov

### reference
1. [document : scipy.stats.kstest](https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.kstest.html)
2. [Youtube : 파이썬을 활용한 통계분석 - (33)콜모고로프-스미르노프 검정(Kolmogorov-Smirnov Test)](https://www.youtube.com/watch?v=28AmUj4ADl4)

---
많은 통계 분석 기법의 경우 `표본이 정규분포를 따른다`라는 가정을 전제로 한다. 따라서 데이터를 다룰 때 각 컬럼이 정규분포를 띄지 않는 것을 확인했다면 반드시 정규화를 수행해야 한다.

또한, 정규화를 수행한 뒤 정규성 검사를 통해 정규성 조건의 충족 여부를 통계적으로 검증해야 하는데, 이 때 보편적으로 사용하는 기법 중 하나가 `Kolmogorov Smirnov Test`이다.

`Kolmogorov Smirnov Test`는 정규분포 뿐만 아니라 특정 분포를 따르는지 판단할 수 있는 기법이다.

`Kolmogorov Smirnov Test`를 사용하기 위해서는 먼저 `scipy`의 `stats` 패키지를 불러와야 한다.

```python
import scipy.stats as stats
```

분석 대상 데이터프레임 `df`에서 특정 컬럼 `age`의 정규성을 검사한다고 하면 아래와 같이 코드를 작성할 수 있다.
```python
stats.kstest(df['age'], 'norm')
```
```
(0.11069395395455, 0.0003342)
```

단일 변수의 정규성 검사를 수행했다. 그 결과 
첫번째 값은 통계 값, 두번째 값은 p-value을 반환했다.

`Kolmogorov Smirnov Test`는 정규성을 검사하며 p-value가 0.5 미만인 경우 귀무가설을 기각, 즉 정규성이 없다고 판단한다.

> 결론 : 위 케이스에서 `age` 변수의 경우 정규분포를 따르지 않는다.






