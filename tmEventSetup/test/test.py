import tmEventSetup
import tmGrammar
menu = tmEventSetup.getTriggerMenu('menu.xml')
algoMap = menu.getAlgorithmMapPtr()
condMap = menu.getConditionMapPtr()
scaleMap = menu.getScaleMapPtr()

indent = '  '

print 'name ', menu.getName()
print 'grammar ', menu.getVersion()
print 'comment ', menu.getComment()
print 'datetime ', menu.getDatetime()
print 'firmware uuid ', menu.getFirmwareUuid()
print 'scale set name ', menu.getScaleSetName()

print 
for key, algo in algoMap.iteritems():
  print "algo name  = ", algo.getName()
  print "algo expr. = ", algo.getExpression()
  print "algo expr. = ", algo.getExpressionInCondition()
  list = algo.getRpnVector()
  for x in list:
    if tmGrammar.isGate(x): continue
    cond = condMap[x]
    print indent*2, "cond type = ", cond.getType()
    cuts = cond.getCuts()
    for y in cuts:
      print y
    objects = cond.getObjects()
    for obj in objects:
      print indent*3, "obj name = ", obj.getName()
      print indent*3, "obj type = ", obj.getType()
      print indent*3, "obj op   = ", obj.getComparisonOperator()
      print indent*3, "obj bx   = ", obj.getBxOffset()
      if obj.getType() == tmEventSetup.EXT:
        name = obj.getName()
        name = obj.getExternalSignalName()
        print indent*3, "ext name = ", name
        print indent*3, "ch id    = ", obj.getExternalChannelId()

      cuts = obj.getCuts()
      for cut in cuts:
        print indent*4, "cut name   = ", cut.getName()
        print indent*4, "cut target = ", cut.getObjectType()
        print indent*4, "cut type   = ", cut.getCutType()
        print indent*4, "cut min value,index = ", cut.getMinimumValue(), cut.getMinimumIndex()
        print indent*4, "cut max value,index = ", cut.getMaximumValue(), cut.getMaximumIndex()
        print indent*4, "cut data = ", cut.getData()


