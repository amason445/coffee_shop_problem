# Coffee Shop Problem - C++ Combinatorial Analysis

## Introduction

While studying probability theory in a coffee shop, I overheard a peculiar conversation. A student mentioned graduating from a degree program with a US GPA that dropped from 3.9 to around 3.67 after failing a final exam. At first, this seemed absurd. The described drop seemed exaggerated because they went from a perfect GPA to an A/B average. I wanted to verify if this was possible.

This was difficult because there are a vast number of possible grade sequences to run the probability for. For example, drawing without replacement from the standard US letter grade system, with 24 courses, there are 2,537,941,990,336 possible grade sequences. Directly computing the probability for each sequence wasn't possible due to processing power and time constraints. Additionally, I had to test against the final GPA and not the raw sequence so there was a transformation in the middle of the calculation.

## Approach

To overcome this difficulty, I decided to run these probabilities assuming the student achieved all As in their courses until a cut off point at n classes. For example, if the cut off point was at 2 classes, this would imply that the student has achieved 22 A grades while class 23 and 24 are left in play. This would simplify the computation to testing for a GPA between 3.6 and 3.7 between 25 total program outcomes.

## Results
In absolute odds, I found that a GPA between 3.6 and 3.7 is most likely to occur when 4 classes are at play. However, it seems significantly less likely to go from a 3.9 to a 3.67 and I'm thinking this more likely to be possible at 2 degrees of freedom. Given that they had a 3.9 before their final exam, and one class swung them to 3.67, I think this likely happened during their last two classes and this had a 4% chance of occuring. It seems this person was very unlucky.

Below are the results from this analysis:
| Degrees of Freedom | Viable Outcomes | Possible Combinations | % Chance |
| ----------- | ----------- | ----------- | ----------- |
| 1 | 0 | 5 | 0% |
| 2 | 1 | 25 | 4% |
| 3 | 25 | 125 | 20% |
| 4 | 165 | 625 | 26.4% |
| 5 | 685 | 3,125 | 21.92% |
| 6 | 2,197 | 15,625 | 14.06% |
| 7 | 5,950 | 78,125 | 7.62% |
| 8 | 14,275 | 390,625| 3.65% |
| 9 | 31,240 | 1,953,125| 1.60% |

## US Letter Grades and Weights
| Letter Grade | GPA Weight |
| ----------- | ----------- |
| A | 4.0 |
| B | 3.0 |
| C | 2.0 |
| D | 1.0 |
| F | 0.0 |

- [US Letter Grading System](https://en.wikipedia.org/wiki/Academic_grading_in_the_United_States)
