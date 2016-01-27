#!/usr/bin/env python

##
#  @author      Takashi Matsushita
#  Created:     07 Jul 2014
#

## @file parser.py demonstration of tmGrammar module functionality
## @todo


import tmGrammar

indent = "  "

print "/////////////////////////////////////////////////////////\n";
print "\t\tA logic parser ...\n";
print "/////////////////////////////////////////////////////////\n";

print "Give me a logic of the form :"
print "  NOT (MU10 AND EG.gt.10p5+1) OR ((NOT TAU15[TAU-ISO_1] AND JET100[JET-ETA_1,JET-ETA_2]) AND (comb{MU10,MU20} AND NOT mass{MU10[MU-PHI_1,MU-ETA_1],EG10}[MASS_1,MASS_2]))\n";

print "Type [q or Q] to quit\n";

while True:
  expression = raw_input("expression: ");
  if ((not expression) or (expression[0] in ['q', 'Q'])): break

  tmGrammar.Algorithm_Logic.clear()
  tmGrammar.Algorithm_parser(expression)

  for token in tmGrammar.Algorithm_Logic.getTokens():
    if token in tmGrammar.gateName:
      print token, " is a Gate"
      continue;

    isMatched = False

    for name in tmGrammar.functionName:
      if name == token[:len(name)]:
        print token, " is a function"
        isMatched = True
        o = tmGrammar.Function_Item()
        tmGrammar.Function_parser(token, o)
        o._print()
        break

    for name in tmGrammar.objectName:
      if name == token[:len(name)]:
        print token, " is an object"
        isMatched = True
        o = tmGrammar.Object_Item()
        tmGrammar.Object_parser(token, o)
        o._print()
        break

    if isMatched: continue
    print "failed to parse '", token, "'"

print "Bye... :-) \n"
#eof
