Variants of euler tour  
- Sabse simple whenever you first visit a node add it to tour and not at the end, just record the time of exit (ye time start to time end denotes your subtree)
- Agla ki start aur end dono pe record krenge tour me. End me time alag se ek badhega. This helps us in getting ancestors of a node and path queries me bhi use kia.
- Ek aur h ki like ek subtree explore krke aaye to fir se node ko daalenge. This is used in LCA.
- Aur ek h ki edges ko sidha record krte chalo kaise kaise traverse kia. vector<pair<int,int>> ban jayega

- Also, Euler tour me 'time' variable ki jroorat sirf uss case me hai jaha sirf ek bar node ko record krte h
- time is nothing but basically the index jaha se subtree of a node start ho rha
- so agar start aur end dono pe node ko daal hi rhe to we know the start and end index waise hi 
