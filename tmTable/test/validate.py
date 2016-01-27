import tmTable
bin = tmTable.Row()
bin["minimum"] = "+2.5000000000000000f+02"
bin["maximum"] = "+2.5500000000000000E+02"
bin["number"] = "1"
print "** bin ",
print tmTable.isBin(bin)

scale = tmTable.Row()
scale["object"] = "TAU";
scale["type"] = "ET";
scale["minimum"] = "+2.5000000000000000E+02"
scale["maximum"] = "+2.5500000000000000E+02"
scale["step"] = "+3.5500000000000000E+02"
scale["n_bits"] = "+3.5500000000000000E+02"
print "** scale ",
print tmTable.isScale(scale)

scaleSet = tmTable.Row()
scaleSet["name"] = "hoge";
print "** scaleSet ",
print tmTable.isScaleSet(scaleSet)

extSignal = tmTable.Row()
extSignal["name"] = "name";
extSignal["system"] = "system";
extSignal["cable"] = "0";
extSignal["channel"] = "1";
print "** extSignal ",
print tmTable.isExtSignal(extSignal)


cut = tmTable.Row()
cut["name"] = "name";
cut["object"] = "object";
cut["type"] = "type";
cut["data"] = "data";
cut["comment"] = "comment";
#cut["hoge"] = "hoge";
print "** cut ",
print tmTable.isCut(cut)

object = tmTable.Row()
object["name"] = "name";
object["type"] = "type";
object["comparison_operator"] = "comparison_operator";
object["threshold"] = "threshold";
object["bx_offset"] = "bx_offset";
object["comment"] = "comment";
object["requirement_id"] = "requirement_id";
object["datetime"] = "datetime";
object["hoge"] = "hoge";
#print "** object ",
print tmTable.isObjectRequirement(object)

algorithm = tmTable.Row()
print tmTable.isAlgorithm(algorithm)

menu = tmTable.Row()
print tmTable.isMenu(menu)
