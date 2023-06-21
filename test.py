#!/usr/bin/python3

import os
import ppp
import json
import sys




if __name__ == "__main__":
    p = ppp.pp_alloc()
    ppp.pp_add(p,4)
    ppp.pp_add(p,5)
    ppp.pp_add(p,6)
    out = ppp.pp_sum(p)
    print(out)


    