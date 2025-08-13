add a check ki if(2*ind+2/1 < lazy.size()) - kahi kahi par runtime error aa jata h
always in case of lazy propagation the first thing you should do in a update / query is addressing the lazy part
uske baad hi fir check kro ki leaf h ya fir requested range se no overlap h to return
isse kya h ki kisi range ka answer galat aa skta because uska ek child update hi ni hua h
