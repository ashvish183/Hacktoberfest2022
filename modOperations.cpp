// MOD operations
ll power(ll a,ll p){
	ll result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}

ll sub(ll x,ll y) {
  return (x % MOD- y % MOD + MOD )%MOD;
}
 
ll add(ll x,ll y) {
  return (x % MOD + y % MOD) % MOD;
}
 
ll multiply(ll a,ll b){
  return ((a % MOD)*(b % MOD)) % MOD;
}
ll divide(ll x,ll y){
  return multiply(x % MOD, power(y, MOD - 2)) % MOD;
}
 
// ncr
ll fact[1000000 + 1];
 
void comb(){
  fact[0] = 1;
  for(ll i = 1; i <= 1000000; i++){
    fact[i] = multiply(fact[i - 1], i);
  }
}
 
ll ncr(ll n, ll r){
  if(r > n || n < 0 || r < 0) return 0;
  if(n == 0 || r == 0){
    return 1;
  }
  ll ans = fact[n];
  ans = divide(ans, fact[r]);
  ans = divide(ans, fact[n - r]);
  return ans;
}