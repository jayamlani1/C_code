// Write any include statements here

int getArtisticPhotographCount(int N, char* C, int X, int Y) {
  // Write your code here
  int photo[N+1]; // Prefix sums for photographer 
  int back[N+1]; // Prefix sums for Backdrop 
  photo[0] = 0;
  back[0] = 0;
  int ans = 0;
  for(int i=1;i<=N;i++) {
    if(C[i-1] == 'P') {
      photo[i] = photo[i-1] + 1;
    }
    else
      photo[i] = photo[i-1];
    
    if(C[i-1] == 'B') {
      back[i] = back[i-1] + 1;
    }
    else
      back[i] = back[i-1];
  }
  
  for(int i=0;i<N;i++) {
    if(C[i] == 'A') {
      int forwardstart = i+X <= N ? i+X : N;
      int forwardend = i+Y+1 <=N ? i+Y+1 : N;
      int backend = i-X+1 >= 0 ? i-X+1 : 0;
      int backstart = i-Y >= 0 ? i-Y :0;
      ans = ans + ((photo[forwardend] - photo[forwardstart] ) * (back[backend] - back[backstart]) );
      ans = ans + ((photo[backend] - photo[backstart] ) * (back[forwardend] - back[forwardstart]) );
      
    }
    
  }
  return ans;
}
