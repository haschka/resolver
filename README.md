# Resolver
A simple generic ip address resolver, that resolves addresses as the system sees them.
As such it allows to query mDNS, wins and other addresses if the system is configured to do so. 

Compile using:
```
gcc resolver.c -o resolver
```

Use like:
```
./resolver myhost.com
```
