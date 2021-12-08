# Stats Final Kahoot

## Questions

The 95% confidence lower bound for p is 0.51.

- The 95% confidence interval suggests that the lowest proportion we can get is 0.51. This means that we are confident that the proportions are greater than 0.50.
- $H_1: p > 0.50$
- `prop.test(x, n, alternative = "greater", correct = F)`

The mean time for a World Series Game is at least 4 hours.

- The alternative hypothesis suggests that the mean is at least, or greater, than 4 hours.
- $H_1: \mu > 4$

The 10th percentile of the Student's t distribution with 12 degrees of freedom is:

- Instead of looking at the t-table, the 10th percentile of the student's t distribution should always be less than 0.
- `qt(10, 12)`

A sample of $n = 50$ is taken from 6000, the 95% interval for $\mu$ is ${18.4,20.9}$. 

- The mean of the 6000 will not always be in the interval.

Data is collected from students about their year in school & job status. Which is incorrect?

- This is a $\chi^2$ test for goodness of fit.
- This is false because goodness of fit tests only have one variable.
- Here, we are tracking the proportion of employed and unemployed students; we are testing to see if the proportion between employed and unemployed students of all years are the same.

A D4 is rolled to determine if it's fair. Which is correct?

- $H_1$: at least one pair of the sides differ.

Assume that linearity holds for $x$ vs. $y$. For $R^2 = 0.99$, as $x$ increases, $y$ will increase as well.

- We don't know the behaviour of $y$ because $R^2$ doesn't tell you the direction of the slope, due to the square. We would need to know the correlation coefficient.

Which does **NOT** indicate a good linear regression model?

- $H_0: \beta_0$ has a p-value of 0.004.
- The intercept does not indicate a good linear regression model.
- $H_0: \beta_1$ having a p-value of 0.004 does; $R^2 = 0.90$ does; normally distributed residuals does.

Let $X$ be the number of A's in a class of 80, where $P(A) = 0.15$.

- $X~Bin(80, 0.15)$

## General Notes

- Be careful whether the confidence interval is upper, lower, or centered. The area covered by the interval will change, meaning that the bounds will change.
    - `alternative = "greater"` for lower bound because we are checking that the mean or proportion is greater than
    - `alternative = "less"` for upper bound because we are checking that the mean or proportion is less than

- `pbinom(80,0.15)` for $P(X \leq x)$
- `dbinom(80,0.15)` for $P(X \leq x)$
- If we know that a distribution is non-symmetric, you should not run $z$ or $t$ confidence tests.
- A type 1 error is where $H_0$ is rejected when it is true,

- A type 2 error is where $H_0$ is accepted when it is false,
k