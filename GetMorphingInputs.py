#!/bin/python

#What this script provides: Yet Another Dictionary

#{coupling
#    { systematicName :
#        { numberOfSigma : [ (mass, file, histogram), (mass, file, histogram), ... ] }
#     }

#Note: the nominal is treated in the same way but systematicName = Nominal and it only has one numberOfSigma that is 0

import SignalDictionaries
from ROOT import *
import pprint

def get_input_filenames(selection="75"):

    if '75' in selection:
        SignalDictionary = SignalDictionaries.dataLikeHists_J10006
    else:
        SignalDictionary = SignalDictionaries.dataLikeHists_J7503
    #print SignalDictionaries.dataLikeHists_J7503
    #mjj_Scaled_m0.55_g0.20_1fb_JET_GroupedNP_1__2up5;1

    #for this step, want a dictionary of masses with the same coupling to feed to the morphing code
    #key: (coupling), value [array of masses]
    CouplingMassSystDict = {}

    #get the list of systematics
    #mjj_Scaled_m0.35_g0.10_1fb_JET_JER_SINGLE_NP__1up

    ListOfSystematics = set()
    ListOfSigmas = set()

    #dummyFile = TFile.Open("dataLikeHists_J10006/dataLikeHistograms.m0.35_g0.10.root")
    dummyFile = TFile.Open("samples/dataLikeHists_J10006_1GeVBins/dataLikeHistograms.m2.00_g0.40.root")
    for key in dummyFile.GetListOfKeys() :
        if "Scaled" not in key.GetName() :
            continue
        histName = key.GetName()
        tokens = histName.split("__")
        #if we can split it, it's a systematics
        try :
            histNameNoSigma = tokens[0]
            nSigma = tokens[1]
            ListOfSystematics.add(histNameNoSigma.split("JET_")[1])
            ListOfSigmas.add(nSigma)
        #if we can't, it's the nominal
        except :
            ListOfSystematics.add("Nominal")

    #print ListOfSigmas, ListOfSystematics

    #deal with nominal first, then systematics

    #loop on signal dictionary and find couplings
    for coupling, CouplingDict in SignalDictionary.iteritems() :
        CouplingMassSystDict[coupling] = {}
        for systematicName in ListOfSystematics :

            CouplingMassSystDict[coupling][systematicName] ={}
            if "Nominal" in systematicName :
                CouplingMassSystDict[coupling][systematicName]["0"] =[]
                for mass, parameterDict in CouplingDict.iteritems() :
                    histName = "mjj_Scaled_m"+mass+"_g"+coupling+"_1fb_Nominal"
                    fileName = "dataLikeHistograms.m"+mass+"_g"+coupling+".root"
                    CouplingMassSystDict[coupling][systematicName]["0"].append((mass, fileName, histName))

            else :
              for sigma in ListOfSigmas :
                  CouplingMassSystDict[coupling][systematicName][sigma] = []

                  for mass, parameterDict in CouplingDict.iteritems() :
                    histName = "mjj_Scaled_m"+mass+"_g"+coupling+"_1fb_JET_"+systematicName+"__"+sigma
                    #print histName
                    fileName = "dataLikeHistograms.m"+mass+"_g"+coupling+".root"
                    #print fileName
                    CouplingMassSystDict[coupling][systematicName][sigma].append((mass, fileName, histName))



    #print "########Dictionary y*<0.3, J75"
    #pp = pprint.PrettyPrinter(indent=10)
    #pp.pprint(CouplingMassSystDict)

    return CouplingMassSystDict


