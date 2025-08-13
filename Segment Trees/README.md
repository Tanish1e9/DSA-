- child nodes ka lazy update tabhi kro jab (low!=high) ho i.e. check ki non-leaf node hona chahye to prevent runtime error
- always in case of lazy propagation the first thing you should do in a update / query is addressing the lazy part
uske baad hi fir check kro ki leaf h ya fir requested range se no overlap h to return
isse kya h ki kisi range ka answer galat aa skta because uska ek child update hi ni hua h
