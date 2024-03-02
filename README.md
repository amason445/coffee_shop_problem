# Coffee Shop Problem - C++ Monte Carlo Simulation

I was studying probability in a coffee shop and I overheard a fascinating conversation. A woman described a situation where she was about to graduate a degree program with a 3.9 but failed a final exam and completed her program with a GPA of around 3.67. At first, I suspected this story was proposterous since there was such a large drop in her GPA of almost all As to a something slightly over a A/B average since carrying a 3.9 would imply all As and maybe a B at the most. So, I wanted to investigate the probability of someone getting this GPA with a sequence of As, then one B and finally any other class score.

This proved to be very difficult because a sequence of letter grades from a school program can be sampled from the below table with replacement. This means there are 2,537,941,990,336 possible combinations. A population I didn't have the processing power and time to brute force.


## US Letter Grades and Weights
| Letter Grade | GPA Weight |
| ----------- | ----------- |
| A | 4.0 |
| B | 3.0 |
| C | 2.0 |
| D | 1.0 |
| F | 0.0 |
