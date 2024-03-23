/* 
    You can either move ahead or backwards and there is a circle with number from 1 to N
    each move takes one second, you need to find the least number of move to complete each jump.
    To begin with you are at 1.
    N=10. input: 9,4,4,8 would take 11 jumps 
    first from 1 to 9 you would either be 8 in forward or 2 in backward. so we will select 2
    second from 9 to 4 will be five in either direction 
    4 to 8 will be 4 in forward and 6 in backward. so select 4
    2 + 5 + 4 = 11 output
  */

long long getMinCodeEntryTime(int N, int M, int* C) {
  // Write your code here
  int prev = 1;
  long long count = 0;
  int fcount = 0; // forward count
  int bcount = 0; // backward count
  for(int i=0;i<M;i++) {
    if(C[i] > prev) {
      fcount = C[i] - prev; // move forward from current position
      bcount = prev + (N-C[i]); // move backward from current position
      //printf("%d %d \n", fcount, bcount);
      count = count + (fcount < bcount ? fcount : bcount);
      //printf("%d\n", count);
    } else if(C[i] < prev) {
      bcount = prev - C[i]; // move back from current position
      fcount = (N-prev) + C[i]; // move forward
      //printf("%d %d \n", fcount, bcount);
      count = count + (fcount < bcount ? fcount : bcount);
      //printf("%d\n", count);
    }
    prev = C[i];
  }
  return count;
}
