long long poww(int value, int power, int toGet) {
  long long ans = 1;
  for(int i=0; i<power; i++) {
    ans = ans * 1LL * value;
    if(ans > toGet) return -1;
  }
  return ans;
}

int NthRoot(int n, int m) {
  int low = 0;
  int high = m;

  while(low <= high) {
    int mid = low + (high - low) / 2;
    long long value = poww(mid, n, m);

    if(value == m) return mid;
    else if(value == -1) high = mid - 1; // calculation gave value greater than m
    else low = mid + 1;
  }
  return -1;
}