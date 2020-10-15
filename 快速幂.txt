int fastpow(int base,int n,int mod){
	int ans=1;
	while(n){
		if(n&1) ans*=base%mod;
		base*=base;
		n>>=1;
	}
	return ans%mod;
}