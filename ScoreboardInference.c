/*
  Question is simple, you can either score 1 or 2 for a problem.
  you will be given a list of values which are the score of students.
  you need to find the minimum number of problems from the scorecard.
  the idea is if there are any odd scores, there is gonna be a question with score 1 and if the max is even.. then there are two test with score 1.
  if the max is odd in that case there is one test with score of 1 and rest with score of 2.
  if max is even and there is not a single score card with odd.. consider all test to be 2 marks
  */

int getMinProblemCount(int N, int* S) {
  // Write your code here
  int odd = 0;
  int max = 0;
  int count = 0;
  for(int i=0;i<N;i++) {
    if(S[i] > max) { 
      max = S[i];
    }
    
    if(S[i]%2 != 0 ) {
      odd = 1;
    }
  }
  
  if(max%2 == 0 && odd == 0) {
    return max/2;
  }
  else if(max%2 == 0 && odd == 1) {
    count = (max - 2) /2;
    count = count + 2;
  } else {
    count = (max - 1) / 2;
    count = count + 1;
  }
  return count;
}
