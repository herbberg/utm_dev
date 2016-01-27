#!/usr/bin/env python

import tmTable
scale = tmTable.Scale()
tmTable.xml2scale('../tmXsd/scale_set.xml', scale)

print 'SCALE_SET'
for key in scale.scaleSet.keys():
  print key, ' = ', scale.scaleSet[key]

print 'SCALE'
print ' # of rows = ', len(scale.scales)
for ii in range(len(scale.scales)):
  row = scale.scales[ii]
  print row["type"], row["minimum"], row["maximum"], row["step"]

  bins = scale.bins[row["object"] + "-" + row["type"]]
  print 'BIN'
  print ' # of rows = ', len(bins)
  for jj in range(0, min(5, len(bins))):
    print bins[jj]["number"], bins[jj]["minimum"], bins[jj]["maximum"]
  print "..."

print dir(scale)
