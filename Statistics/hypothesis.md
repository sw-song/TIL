# 범주형/연속형 변수 조합에 따른 가설 검정 방법

## 1. 단일변수
### 1-1. 연속형
- 정규성 검정
- One Sample T-Test(일표본 평균검정)
```py
# One Sample T-Test : 
## 귀무가설 H0 - 특정 값은 집단의 평균과 다르지 않다. (H0확률 = p-value, 0.05 미만이면 기각)
## 연구가설 H1 - 특정 값은 집단의 평균과 다르다.
stats.ttest_1samp(Series, value) # 집단의 평균(Series) vs 검증하고자 하는 값(value)
```

### 1-2. 범주형
- 비율 검정(ex. 연구가설 H1-집단 내 남녀 비율은 차이가 있다)

---
## 2. 다변수
### 2-1. 범주형 'X' & 연속형(정규분포) 'Y'
- Two Sample T-Test(이표본 평균검정), 등분산 검정(Levene Test)
- 등분산 검정 결과에 따라(이분산, 등분산) Two Sample T-Test를 다르게 수행
```py
# 등분산 검정
## 귀무가설 H0 - 두 집단의 분산은 다르지 않다
## 귀무가설 H0 - 두 집단의 분산은 서로 다르다
stats.levene(Series1, Series2)
stats.fligner(Series1, Series2)
stats.bartlett(Series1, Series2)

# 등분산 조건 충족시
stats.ttest_ind(Series1, Series2, equal_var=True)
# 등분산 조건 불충족시
stats.ttest_ind(Series1, Series2, 
equal_var=False)
```


### 2-2. 범주형 'X' & 연속형(비-정규분포) 'Y'
- 비모수적 검정
### 2-3. 범주형 'X' & 범주형 'Y'
- Chi Square 검정(두 범주형 집단의 독립성 검정)
```py
# 카이제곱 검정
## 귀무가설 H0 - 두 집단은 서로 독립이다
## 연구가설 H1 - 두 집단은 서로 독립이 아니다(의존적이다)
crosstable = pd.crosstab(Series1, Series2) # 빈도 계산 - Contingency Table
stats.chi2_contingency(crosstable)
#-> result : (stats, p-value, 자유도, 모수추정값)
#-> p-value < 0.05 : 귀무가설 기각 - 독립이 아니다. 
#-> ex 자동차 구매 - 계약 유형(Series1)에 따라 제품군(Series2)의 차이가 있다

```
### 2-4. 연속형 'X' & 연속형 'Y'
- 상관분석, 회귀분석
### 2-5. 연속형 'X' & 범주형 'Y'
- 로지스틱 회귀분석(분류문제)



