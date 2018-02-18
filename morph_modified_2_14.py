
import sys
import re
import ROOT
import array
import GetMorphingInputs
import SignalDictionaries

doNotExtrapolate = True
tryNonlinearMorphs = False

def mass_grid():
    # drop points for J75 below 500 gev
    masses_low = [(50*x + 500)/1000. for x in range(0,20)]
    masses_high = [(100*x+1500)/1000. for x in range(0,4)]
    masses = masses_low + masses_high + [0.725]
    return masses
# TEST COMMENT

def nondestructive_update_sample_dictionary( gq , mass , key , value , dictionary ):
    if not gq in dictionary:
        dictionary[ gq ] = {}
    if not mass in dictionary[gq]:
        dictionary[ gq ][ mass ] = {}
    if not key in dictionary[ gq ][ mass ]:
        dictionary[ gq ][ mass ][ key ] = value
    else:
        # sanity check for values already dictionary
        ref = dictionary[ gq ][ mass ][ key ]
        if ref>0 or ref<0:
            diffratio = ( value - ref)/ref
        else:
            diffratio = 0
        # if diffratio>0.01 or diffratio<-0.01:
        if (value-ref)>0.01 or (value-ref)<-0.01:
            print "CAUTION: interpolated %s value of %3.2f differs from input value %3.2f by fraction %3.2f for coupling %s mass %s" % (key,value,ref,diffratio,gq,mass)
        
    return dictionary

def escape_floating_point( input_string ):
    return re.sub('\.','p', input_string )


def loop_iterator(iterator):
    # use to loop on a RooArgSet (from https://gist.github.com/wiso/b87a1ef19573cd2c5b93e61cb33f1856)
    object = iterator.Next()
    while object:
        yield object
        object = iterator.Next()


def iter_collection(rooAbsCollection):
    # use to loop on a RooAbsCollection (from https://gist.github.com/wiso/b87a1ef19573cd2c5b93e61cb33f1856)
    iterator = rooAbsCollection.createIterator()
    return loop_iterator(iterator)


def minmax_masses( dictionary ):
    results = {}
    print 'in minmax_masses'
    for (gq,masses) in dictionary.iteritems():
        minx = 99999
        maxx = 0
        for (mass,val) in masses.iteritems():
            if float(mass) < minx:
                minx = float(mass)
            if float(mass) > maxx:
                maxx = float(mass)
        print 'gq: %s mass min: %f max: %f' % (gq,minx,maxx)
        results[gq] = [minx,maxx]
    return results

def fits_for_normalization_parameters(dictionaries, fitFunction, fitFuncXmin, fitFuncXmax, parameter, Plot):
    
    #Function to fit the plots of "parameter" vs mass for each dictionary
    #fitFunction -> string with the fir equation
    #fitXmin/fitXmax -> floats with min/max values of fit range
    #parameter -> string describing the parameter to be fit e.g. "xsec" or "acc"
    #plot-> bool enabling/disabling display of the plots

    fits = []
    
    for (dictname,whichdict) in dictionaries.iteritems():
        ROOT.gStyle.SetOptFit(111111)
        if parameter == "xsec":
            h = ROOT.TH2D("frame","",10,0,2,10,0.1,1000)
        if parameter == "acc":
            h = ROOT.TH2D("frame","",10,0,4,10,0.01,1)
        h.Draw()
        ROOT.gPad.SetLogy(1)
        for gq in whichdict:
            print "gq: ", gq
            print "======"
            g = ROOT.TGraph()
            n = 0
            gqchoice = gq
            if '0.15' in gq and parameter == "acc":
                gqchoice = '0.10'
            for (mass,d) in whichdict[gqchoice].iteritems():
                dir(d)
                if parameter == "xsec" and not 'theory' in d:
                    continue
                if parameter == "acc" and not 'acc' in d:
                    continue
                print mass,d['theory']
                g.SetPoint(n,float(mass),d['theory'])
                n=n+1
            g.SetMarkerSize(2)
            g.SetMarkerStyle(8)
            g.Draw("p")
            func = ROOT.TF1("mp",fitFunction,fitFuncXmin,fitFuncXmax)
            ################################ Less-Than-Ideal Mess ###############################
            #This is completely unchanged from Antonio's code
            #Should think about how to make it more automated
            if parameter == "acc":
                minfitx = 0.39
                maxfitx = 2
                func.SetParLimits(3,1,20)
                func.SetParLimits(4,-100,0)
                if gq=="0.10" and dictname=="10006":
                    #maxfitx=1.8
                    func.SetParLimits(0,0.,0.6)
                    func.SetParLimits(1,0.,2)
                    func.SetParLimits(2,5,20)
                if gq=="0.15" and dictname=="10006":
                    #maxfitx=1.8
                    func = ROOT.TF1("mp","[0]/(1+exp(-(x-[1])*[2]))",0,2)
                    func.SetParameter(0,0.228)
                    func.SetParameter(1,0.5932)
                    func.SetParameter(2,16.82)
                    # func.SetParLimits(0,0.,0.3)
                    # func.SetParLimits(1,0.1,1)
                    # func.SetParLimits(2,5,25)
                    # func.SetParLimits(3,0,0)
                    # func.SetParLimits(4,0,0)
                if gq=="0.15" and dictname=="7503":
                    #maxfitx=1.8
                    func.SetParLimits(0,0.,0.1)
                    func.SetParLimits(1,0.,2)
                    func.SetParLimits(2,0.1,100)
                    func.SetParLimits(3,0,0)
                    func.SetParLimits(4,0,0)
                if gq=="0.20" and dictname=="10006":
                    #maxfitx=1.8
                    func.SetParLimits(0,0.,0.5)
                    func.SetParLimits(1,0.,2)
                    func.SetParLimits(2,5,20)
                if gq=="0.30" and dictname=="10006":
                    #maxfitx=1.8
                    func.SetParLimits(0,0.,0.5)
                    func.SetParLimits(1,0.,2)
                    func.SetParLimits(2,5,20)
                if gq=="0.40" and dictname=="10006":
                    #maxfitx=1.8
                    func.SetParLimits(0,0.,0.5)
                    func.SetParLimits(1,0.,2)
                    func.SetParLimits(2,5,20)
                if gq=="0.40" and dictname=="7503":
                    #maxfitx=1.8
                    func.SetParLimits(0,0.,0.4)
                    func.SetParLimits(1,0.,2)
                    func.SetParLimits(2,5,20)
                if gq=="0.20" and dictname=="7506":
                    minfitx=0.5
                    maxfitx=1.8
                    func = ROOT.TF1("mp","[0]/(1+exp(-(x-[1])*[2]))",0,2)
                    # func.SetParameter(0,0.228)
                    # func.SetParameter(1,0.5932)
                    # func.SetParameter(2,16.82)
                    # func.SetParLimits(0,0.,0.4)
                    # func.SetParLimits(1,0.,2)
                    # func.SetParLimits(2,5,20)
           ############################# end of Less-Than-Ideal mess ###########################
            g.Fit(func,"Wm+")
            if Plot:
                ROOT.gPad.Print(parameter+"_"+gq+"_"+dictname+".pdf")
            fits.append( { 'selection': dictname ,
                              'gq': gq ,
                           'function' : func } )

    return fits

def fit_cross_sections(masses, dictionaries):

    fitFunction = "[0]*x^(-4+[1])*(1-(x/7))^[2]"
    fitFuncXmin = 0
    fitFuncXmax = 2.01
    parameter = "xsec"
    #fits = []
    results = []
    makePlots = True

    fits = fits_for_normalization_parameters(dictionaries, fitFunction, fitFuncXmin, fitFuncXmax, parameter, makePlots)

     # summarize results
    for f in fits:
        print "fit_cross_sections:"
        print "gq: %s selection: %s" % (f['gq'],f['selection'])
        print "======================"
        f['function'].Print("v")
        for mass in masses:
            print "mass: %f  pred: %32.16f" % (mass, f['function'].Eval(mass) )
    
    # write dictionaries
    massranges = {}
    print dictionaries
    for (dname,d) in dictionaries.iteritems():
        massranges[dname] = minmax_masses( d )
        
    print "dictionaries: "
    for f in fits:
        for mass in masses:
            massstr = "%3.2f" % (mass)
            xsec = f['function'].Eval(mass)
            if doNotExtrapolate and (mass<massranges[f['selection']][f['gq']][0] or mass>massranges[f['selection']][f['gq']][1]):
                continue
            d = dictionaries[f['selection']]
            d = nondestructive_update_sample_dictionary( f['gq'], massstr ,
                                                         'theory' , xsec , d )
            dictionaries[f['selection']] = nondestructive_update_sample_dictionary( f['gq'], massstr ,
                                                                                    'dsid' , 0 , d )
    return dictionaries
    
        

def fit_acceptances(masses, dictionaries):

    # sigmoid is ok but needs work
    #   - [1] needs constraint
    #   - augment to model a slow decline at high mass (due to y* cut?)

    fitFunction = "[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))"
    fitFuncXmin = 0
    fitFuncXmax = 2
    parameter = "acc"
    #fits = []
    results = []
    makePlots = True

    fits = fits_for_normalization_parameters(dictionaries, fitFunction, fitFuncXmin, fitFuncXmax, parameter, makePlots)

    # summarize results
    for f in fits:
        print "fit acceptances:"
        print "gq: %s selection: %s" % (f['gq'],f['selection'])
        print "======================"
        f['function'].Print("v")

    # write dictionaries
    massranges = {}
    for (dname,d) in dictionaries.iteritems():
        massranges[dname] = minmax_masses( d )
    print "dictionaries: "
    for f in fits:
        for mass in masses:
            massstr = "%3.2f" % (mass)
            acc = f['function'].Eval(mass)

            if doNotExtrapolate and (mass<massranges[f['selection']][f['gq']][0] or mass>massranges[f['selection']][f['gq']][1]):
                continue
            d = dictionaries[f['selection']]
            dictionaries[f['selection']] = nondestructive_update_sample_dictionary( f['gq'], massstr ,
                                                                                    'acc' , acc , d )
    return dictionaries

def compute_nexpected(dictionary,coupling,mass):
    if (not coupling in dictionary) or (not mass in dictionary[coupling]):
        print "FATAL: missing updated dictionary for morphed point gq: %s mass:%s" % (coupling,mass)
        exit()
    d = dictionary[coupling][mass]
    if not 'theory' in d or not 'acc' in d:
        print "FATAL: missing updated dictionary for morphed point gq: %s mass:%s" % (coupling,mass)
        print d
        exit()
    nexpected = d['acc']*d['theory']*1000
    return nexpected

def renormalize_th1(th1,nnew):
    n = th1.Integral()
    s = 1
    if n>0:
        s = nnew/n
    th1.Scale(s)
    return th1

        
def make_hist_pdfs(list_of_inputs,mass):
    # make hist PDFs out of each input TH1
    # the list_of_inputs dictionary argument should have the form:
    #    [float(mass),TH1F]
    # returns a list of dictionaries of the form
    #    [{'name':string(name),'pdf':RooHistPdf,'mass':float(mass)}]
    result = []
    for (massval,h) in list_of_inputs.iteritems():
        #hname = "mass_%f"%(massval)
        hname = h.GetName()
        variables = ROOT.RooArgList(mass)
        hist = TH1(h)
        hdata = ROOT.RooDataHist( hname , hname , ROOT.RooArgList(variables) , hist )
        hpdf = ROOT.RooHistPdf( hname , hname , ROOT.RooArgSet(mass) , hdata )
        result.append( { 'name': hname , 'pdf': hpdf , 'mass': float(massval) } )
    return result

def make_hist_pdf(workspace,massvar,htuple):
    # make a hist PDF out of the input TH1
    # returns a dictionary of the form
    #    {'name':string(name),'pdf':RooHistPdf,'mass':float(mass)}
    result = []
    (hist,hname) = htuple
    print "creating PDF:",hist,hname
    # print "test"
    # dir(hist)
    # print hist
    if not hist:
        print "FATAL: histogram shouldn't be null here: %s" % (hname)
    hdata = ROOT.RooDataHist( hname , hname , ROOT.RooArgList(massvar) , hist )
    hpdf = ROOT.RooHistPdf( hname , hname , ROOT.RooArgSet(massvar) , hdata )
    getattr(workspace,'import')(hdata)
    getattr(workspace,'import')(hpdf)
    return hpdf


def rebin_unitGeV_histogram(histogram):
    # rebins TH1 'histogram' (with 1 GeV bins) into the standard binning
    # binning = [x/1. for x in [0, 362, 381, 400, 420, 441, 462, 484, 507, 531, 555, 580, 606, 633, 661, 690, 720, 751, 784, 818, 853, 889, 927, 966, 1007, 1049, 1093, 1139, 1186, 1235, 1286, 1339, 1394, 1451, 1511, 1573, 1637, 1704, 1773, 1845, 1920, 1998, 2079, 2163, 2251, 2342, 2437, 2536, 2639, 2746, 2857, 2973, 3094, 3220, 3351, 3487, 3629, 3776, 3929, 4088, 4254, 4427, 4607, 4794, 4989, 5191, 5402, 5621, 5849, 6086, 6333, 6590, 6857, 7135, 7425, 7726, 8040, 8366, 8706, 9059, 9427, 9810, 10208, 10622, 11053, 11502, 11969, 12455, 12960, 13486, 14000]]
    binning = [ 362, 381, 400, 420, 441, 462, 484, 507, 531, 555, 580, 606, 633, 661, 690, 720, 751, 784, 818, 853, 889, 927, 966, 1007, 1049, 1093, 1139, 1186, 1235, 1286, 1339, 1394, 1451, 1511, 1573, 1637, 1704, 1773, 1845, 1920, 1998, 2079, 2163, 2251, 2342, 2437, 2536, 2639, 2746, 2857, 2973, 3094, 3220, 3351, 3487, 3629, 3776, 3929, 4088, 4254, 4427, 4607, 4794, 4989, 5191, 5402, 5621, 5849, 6086, 6333, 6590, 6857, 7135, 7425, 7726, 8040, 8366, 8706, 9059, 9427, 9810, 10208, 10622, 11053, 11502, 11969, 12455, 12960 , 13486]
    numberOfBins = len(binning)-1
    rebinnedHist = histogram.Rebin(numberOfBins, "rebinned", array.array('d',binning));
    return rebinnedHist
    

        
def load_inputs_old():
    # returns dictionary of the form:
    #    [float(mass),TH1F]
    f = ROOT.TFile.Open("sampleHists.root")
    result = {}

    # mjj_Scaled_m2.00_g0.40_1fb_Nominal
    # list of all systematics
    # list of all input files
    
    
    shortfile = { "0p35":350 ,
                  "0p45":450 ,
                  "0p55":550 ,
                  "0p6":600 ,
                  "0p65":650 ,
                  "0p75":750 ,
                  "0p8":800 ,
                  "0p85":850 ,
                  "0p95":950 ,
                  "1p0":1000 ,
                  "1p05":1050 ,
                  "1p15":1150 ,
                  "1p5":1500 ,
                  "1p7":1700 ,
                  "2p0":2000 ,
                  "2p5":2500 ,
                  "3p0":3000 ,
                  "3p5":3500 }

    for (mR,val) in shortfile.iteritems():
        shortname = "mR"+mR+"_mDM10_gSM0p10_gDM1p5"
        longname = "mjj_Scaled_"+shortname+"_1fb_"
        if f.Get(longname)==0:
            continue
        h = f.Get(longname)
        if h==False:
            continue
        print longname
        print h
        print h.GetName()
        result[val] = h

    return result
    

def test_morph_old():

    inputs = load_inputs_old()
    mh = morph(inputs,501)

    first = True
    for (mass,h) in iteritems(list_of_inputs):
        if first:
            h.GetXaxis().SetRangeUser(0,2000)
            h.Draw()
            first = False
        else:
            h.Draw("same")


    mh.SetLineColor(ROOT.kRed)
    mh.Draw("same")
    ROOT.gPad.Print("morph_test.pdf")

def load_inputs(selection='7503'):

    CouplingMassSystDict = GetMorphingInputs.get_input_filenames(selection)

    if '10006' in selection:
        baseDir = 'samples/dataLikeHists_J10006_1GeVBins_fixed'
    elif '7503' in selection:
        baseDir = 'samples/dataLikeHists_J7503_1GeVBins_fixed'
    elif '7506' in selection:
        baseDir = 'samples/dataLikeHists_J7506_1GeVBins_fixed'
    else:
        print "FATAL unrecognized selection"
        exit()
    
    
    # get histograms for each
    #    coupling value
    #    mass value
    #    systematic name
    #    systematic value

    results = {}
    postfix = "" # or "_copy", added to the name of all histograms
    for coupling, couplingDict in CouplingMassSystDict.iteritems():
      for systematicName, systematicSigmaDict in couplingDict.iteritems():
        #myVectorOfInputForMorphing = []
        #print systematicSigmaDict
        for (sigma, massVector) in systematicSigmaDict.iteritems():
            for (mass,fileName,histogram) in massVector:
              # print massVector
              f = ROOT.TFile.Open(baseDir+'/'+fileName,"READ")
              if not f or not f.IsOpen():
                  if not mass in mass_grid():
                      print "WARNING: missing " + baseDir+'/'+fileName
                      continue
              h = f.Get(histogram)
              if not h:
                  print "WARNING could not get histogram: %s from file: %s" % (histogram,baseDir+'/'+fileName)
                  continue
              else:
                  if False and '0.05' in coupling:
                      print "OKAY histogram: %s from file: %s with %d entries and integral %f" % (histogram,baseDir+'/'+fileName,h.GetEntries(),h.Integral())
              h = h.Clone(histogram+postfix)
              h.SetDirectory(0)
              if not h:
                  print "WARNING could not get histogram: %s from file: %s" % (histogram,baseDir+'/'+fileName)
              #myVectorOfInputForMorphing.append(h)
              if not coupling in results:
                  results[coupling] = {}
              if not mass in results[coupling]:
                  results[coupling][mass] = {}
              if not systematicName in results[coupling][mass]:
                  results[coupling][mass][systematicName] = {}
              results[coupling][mass][systematicName][sigma] = (h,histogram+postfix)
              if not h:
                  print "FATAL: histogram shouldn't be null here: %s" % (histogram+postfix)
                  exit()
              f.Close()
              if not h:
                  print "FATAL: histogram shouldn't be null here: %s" % (histogram+postfix)
                  exit()
          
          
    
    # for (mR,val) in shortfile.iteritems():
    #     shortname = "mR"+mR+"_mDM10_gSM0p10_gDM1p5"
    #     longname = "mjj_Scaled_"+shortname+"_1fb_"
    #     if f.Get(longname)==0:
    #         continue
    #     h = f.Get(longname)
    #     if h==False:
    #         continue
    #     print longname
    #     print h
    #     print h.GetName()
    #     result[val] = h
    return results
        



def get_list_of_systematics(inputs):
    # list of systematics (names) should be the same for every mass point
    systematics = list(inputs['0.05']['0.65'].keys())
    return systematics


def get_list_of_systematic_variations(inputs,systematic):
    # list of systematics (names) should be the same for every mass point
    variations = list(inputs['0.05']['0.65'][systematic].keys())
    return variations


def get_list_of_couplings(inputs):
    # get list of couplings
    return list(inputs.keys())


def get_list_of_masses(inputs,coupling):
    return list(inputs[coupling].keys())

def save_morph_input_histogram_validation(inputs,outname):
    first = True
    dir(inputs)
    print dir(inputs)
    for (h,name) in inputs:
        if first:
            h.GetXaxis().SetRangeUser(200,2000)
            h.Draw()
            first = False
        else:
            h.Draw("same")
    ROOT.gPad.Print( outname + ".pdf" )
    ROOT.gPad.Print( outname + ".C" )

def build_morphing_inputs(inputs , coupling , systName , systVal , massvar , workspace):
    # builds a list of pairs of: histograms (RooHistPdf) and the corresponding mass parameter (alphas)
    results = {}
    # get the list of masses to consider
    masses = get_list_of_masses(inputs,coupling)
    # debug
    if False:
        for alpha in masses:
            save_morph_input_histogram_validation(inputs[coupling][alpha][systName][systVal],"test_%s"%(alpha))
    # get the histograms (TH1x) - transform mass values to (mass,histogram) pairs
    pdfs = [ (make_hist_pdf(workspace,massvar,inputs[coupling][alpha][systName][systVal]),alpha) for alpha in masses ]
    #print histograms
    print pdfs
    return pdfs


def save_morph_validation(workspace,name):
    frame = workspace.var("dijet_mass").frame( ROOT.RooFit.Range(200,2000) );    
    for pdf in loop_iterator(workspace.allPdfs().createIterator()):
        # print pdf
        # dir(pdf)
        # print pdf.ClassName()
        histpdf = workspace.pdf(pdf.GetName())
        histpdf.plotOn( frame , ROOT.RooFit.LineColor(ROOT.kBlue) , ROOT.RooFit.LineStyle(ROOT.kSolid) )
    morphedpdf = workspace.pdf("morphedpdf")
    morphedpdf.plotOn( frame , ROOT.RooFit.LineColor(ROOT.kRed) , ROOT.RooFit.LineStyle(ROOT.kDashed) )
    ROOT.gPad.Print( name + ".pdf" )
    
def save_morph_input_validation(workspace,name):
    massvar = workspace.var("dijet_mass")
    frame = massvar.frame( ROOT.RooFit.Range(200,2000) );

    iter = workspace.allPdfs().createIterator()
    pdf = iter.Next()
    while pdf :
        pdf.plotOn( frame )
        pdf = iter.Next()        
    ROOT.gPad.Print( name + ".pdf" )


def writeOutputHistogram( h , selection , coupling , mass , systematic , variation ):

    if '10006' in selection:
        selStr = 'J10006'
    elif '7503' in selection:
        selStr = 'J7503'
    elif '7506' in selection:
        selStr = 'J7506'
    else:
        print "FATAL unrecognized selection"
        exit()
    outDir = "samples/dataLikeHists_"+selStr+"_1GeVBins_fixed_morphed"

    filename = "dataLikeHistograms.m%s_g%s.root" % (mass,coupling)
    if 'Nominal' in systematic:
        histname = ("mjj_Scaled_m%s_g%s_1fb_%s")%(mass,coupling,systematic)
    else:
        histname = ("mjj_Scaled_m%s_g%s_1fb_JET_%s__%s")%(mass,coupling,systematic,variation)
        
    f = ROOT.TFile.Open(outDir+"/"+filename,"UPDATE")
    if not f:
        print "FATAL: can't open file %s" % (outDir+"/"+filename)
        
    h.SetDirectory(f)
    h.SetName(histname)
    h.Write()
    f.Close()
    
    
def morph_modified_2_14(inputs,dictionaries,selection,coupling,systematic,variation,outputMasses,savePlots=False,unbiasedTest=True):

    w = ROOT.RooWorkspace("w",False)

    max_mass = 12960 # integer in TeV
    massName = "dijet_mass"
    massvar = ROOT.RooRealVar( massName , "dijet mass" , 0 , max_mass , "GeV" )
    # would write w.import(mass), but 'import' is a python keyword, so need this workaround
    getattr(w,'import')(massvar)

    input_masses = get_list_of_masses(inputs,coupling)

    #print get_list_of_systematic_variations(inputs,'Nominal')
    
    morphing_inputs = build_morphing_inputs(inputs , coupling , systematic , variation , massvar , w )

    #getattr(w,'writeToFile')("workspace.root")
    getattr(w,'Print')()

    #save_morph_input_validation(w,"morph_input_g%s_s%s_v%s"%(coupling,systematic,variation))

    (alphamin,alphamax) = minmax_masses(SignalDictionaries.dataLikeHists_J7503.copy())[coupling]

    for outputMass in outputMasses:

        # skip output masses that are outside the range of input masses
        if doNotExtrapolate and (float(outputMass) < alphamin or float(outputMass) > alphamax):
            print "WARNING: skipping morphing mass %3.2f because it is outside the range %3.2f to %3.2f TeV" % (float(outputMass),alphamin,alphamax)
            continue

        # import the morphing inputs into the workspace and create strings for configuring the moment morphing
        if unbiasedTest:
            testMass = float(outputMass)
        else:
            testMass = 0
            # if not making a comparison with input MC, do not perform morphing for masses that exist in the inputs
            if ('%3.2f'%(outputMass)) in input_masses:
                continue

        pdfNames = []
        pdfAlphas = []
        for (pdf,alpha) in morphing_inputs:
            # skip the test mass, if an unbiased comparison is requested
            if testMass>0 and ('%3.2f'%(testMass)) in alpha:
                continue
            # if not pdf:
            #     print "FATAL: no pdf for alpha: %s for %s" % (alpha)
            #     exit()
            # else:
            #     print "OKAY: pdf: %s for alpha: %s" % (pdf.GetName(),alpha)
            pdfNames.append( pdf.GetName() )
            pdfAlphas.append( alpha )
        argPdfNames = ",".join(pdfNames)
        argPdfAlphas = ",".join(pdfAlphas)
        argAlphaMinMax = "[%f,%f]" % (alphamin,alphamax)
            
        # construct moment morph
        # interpolation settings: Linear, NonLinear, NonLinearPosFractions, NonLinearLinFractions, SineLinear
        # try Linear first, then others if that fails
        alphaName = "mR"

        for morphMode in [ 'Linear' , 'NonLinearPosFractions', 'NonLinearLinFractions' ]:
            # only try to recover from a failed nonlinear morph when in a special running mode (set by the tryNonlinearMorphs bool)
            if not tryNonlinearMorphs and (morphMode!='Linear'):
                continue
            morphPdfName = "morphpdf" + morphMode
            factoryString = "RooMomentMorph::"+morphPdfName+"("+alphaName+""+argAlphaMinMax+","+massName+",{"+argPdfNames+"},{"+argPdfAlphas+"},"+morphMode+")"
            print factoryString
            w.factory(factoryString)
            mR = w.var(alphaName)
            mR.setVal(float(outputMass))
            morphedpdf = w.pdf(morphPdfName)
            morphedhist = morphedpdf.createHistogram(massName,max_mass)
            if morphedhist and morphedhist.Integral()>0:
                print "MORPHED: %s_g%s_m%f_s%s_v%s"%(selection,coupling,outputMass,systematic,variation
                ) + " with mode %s" % (morphMode)
                break
            
        rebinned_morphed_hist = rebin_unitGeV_histogram(morphedhist)
        # renormalize output histogram to Scaled crosssection*acceptance*1000/pb
        #   neglects how systematic variations change the acceptance, but this
        #   was verified to be smaller than 5% except for points now removed
        #   from the morphing output (e.g. for J7503, below 500 GeV or above 1.9 TeV)
        nexpected = compute_nexpected(dictionaries[selection],coupling,'%3.2f'%(outputMass))
        rebinned_morphed_hist = renormalize_th1(rebinned_morphed_hist,nexpected)
        #writeOutputHistogram( rebinned_morphed_hist , selection , coupling , outputMass , systematic , variation )
        if savePlots:
            # save validation plot
            systName = systematic
            systVal = variation
            ROOT.gStyle.SetOptFit(111111)
            ROOT.gPad.SetLogy(0)
            # h = ROOT.TH2D("morphframe","",10,400,1000,10,0,1)
            # h.Draw()
            firstDraw = True
            # get the histograms (TH1x)
            allh = [ inputs[coupling][alpha][systName][systVal] for alpha in input_masses ]
            for (h,hname) in allh:
                if not h:
                    continue
                rebinh = rebin_unitGeV_histogram(h)
                if not rebinh:
                    continue
                rebinh.SetLineColor(ROOT.kBlue)
                rebinh.SetLineWidth(1)
                rebinh.SetName( escape_floating_point('input_%s' % (alpha)) )
                if firstDraw:
                    firstDraw = False
                    rebinh.GetXaxis().SetRangeUser(400,2000)
                    rebinh.DrawNormalized("hist")
                else:
                    rebinh.DrawNormalized("same hist")
            if rebinned_morphed_hist:
                rebinned_morphed_hist.SetLineColor(ROOT.kRed)
                rebinned_morphed_hist.SetLineWidth(2)
                rebinned_morphed_hist.SetLineStyle(ROOT.kDashed)
                # rebinned_morphed_hist.GetXaxis().SetRangeUser(400,2000)
                # rebinned_morphed_hist.SetMaximum(0.5)
                rebinh.SetName( escape_floating_point('morph_%3.2f' % (outputMass)) )
                if firstDraw:
                    rebinned_morphed_hist.DrawNormalized("hist")
                    firstDraw = False
                else:
                    rebinned_morphed_hist.DrawNormalized("hist same")
            ROOT.gPad.Print( escape_floating_point("morph_%s_g%s_m%f_s%s_v%s"%(selection,coupling,outputMass,systematic,variation))+".pdf" )
            #ROOT.gPad.Print( escape_floating_point("morph_%s_g%s_m%f_s%s_v%s"%(selection,coupling,outputMass,systematic,variation))+".C" )
     

def fit_normalizations(selection,nominal_dict):
    inputs = load_inputs(selection)
    for coupling in get_list_of_couplings(inputs):
        input_masses = get_list_of_masses(inputs,coupling)
        nominal_hs = [ inputs[coupling][alpha]['Nominal']['0'][0] for alpha in input_masses ]
        nominal_norms = [ nominal_dict[coupling][alpha]['theory']*nominal_dict[coupling][alpha]['acc']*1000 for alpha in input_masses ]
        for syst in get_list_of_systematics(inputs):
            if 'Nominal' in syst:
                continue
            for var in get_list_of_systematic_variations(inputs,syst):
                syst_hs = [ inputs[coupling][alpha][syst][var][0] for alpha in input_masses ]
                norms = [ h.Integral() for h in syst_hs ]
                ratios = []
                for n in range(0,len(norms)):
                    ratio = norms[n]/nominal_norms[n]
                    ratios.append( ratio )
                    #if ratio>1.05 or ratio<0.95:
                    #if ratio>1.01 or ratio<0.99:
                    #print "CAUTION: coupling: %s syst: %s sigma: %s mass: %s ratio: %8.5f" % (coupling,syst,var,input_masses[n],ratio)
                    if float(input_masses[n]>0.5) and (ratio>1.05 or ratio<0.95):
                        print "CAUTION: coupling: %s syst: %s sigma: %s mass: %s ratio: %8.5f" % (coupling,syst,var,input_masses[n],ratio)
                
                if False:
                    ROOT.gStyle.SetOptFit(111111)
                    h = ROOT.TH2D("frame","",10,0.1,2.000,10,0.5,1.5)
                    h.Draw()
                    ROOT.gPad.SetLogy(0)
                    fmasses = [ float(alpha) for alpha in input_masses ]
                    g = ROOT.TGraph( len(fmasses) , array.array('d',fmasses) , array.array('d',ratios) )
                    g.Draw("p")
                    g.SetMarkerSize(1)
                    g.SetMarkerStyle(8)
                    ROOT.gPad.Print("norm_sel%s_g%s_syst%s_var%s.pdf" % (selection,coupling,syst,var))
                    


def test_normalizations(selection,nominal_dict):
    inputs = load_inputs(selection)
    coupling = '0.15'
    input_masses = get_list_of_masses(inputs,coupling)
    nominal_hs = [ inputs[coupling][alpha]['Nominal']['0'][0] for alpha in input_masses ]
    norms = [ h.Integral() for h in nominal_hs ]
    pred_norms = [ nominal_dict[coupling][alpha]['theory']*nominal_dict[coupling][alpha]['acc']*1000 for alpha in input_masses ]
    print norms
    print pred_norms
    for n in range(0,len(norms)):
        print "mass: %s ratio: %8.5f" % (input_masses[n],pred_norms[n]/norms[n])

def test_normalizations_syst(selection,nominal_dict):
    inputs = load_inputs(selection)
    coupling = '0.15'
    syst = "TLA_ScaleFactor"
    var = "3down"
    input_masses = get_list_of_masses(inputs,coupling)
    nominal_hs = [ inputs[coupling][alpha]['Nominal']['0'][0] for alpha in input_masses ]
    syst_hs = [ inputs[coupling][alpha][syst][var][0] for alpha in input_masses ]
    norms = [ h.Integral() for h in nominal_hs ]
    syst_norms = [ h.Integral() for h in syst_hs ]
    print norms
    print syst_norms
    print "for %s %s %s" % (coupling,syst,var)
    for n in range(0,len(norms)):
        print "mass: %s ratio: %8.5f" % (input_masses[n],syst_norms[n]/norms[n])
        

# interpolate cross sections and acceptances for points in mass_grid()

J7503_Dict = SignalDictionaries.dataLikeHists_J7503.copy()
J7506_Dict = SignalDictionaries.dataLikeHists_J7506.copy()
J10006_Dict = SignalDictionaries.dataLikeHists_J10006.copy()
dicts = { '7503': J7503_Dict,
          '7506': J7506_Dict,
          '10006': J10006_Dict }

if True:
    # interpolate theory cross section and nominal acceptance
    dicts = fit_cross_sections(mass_grid(),dicts)
    dicts = fit_acceptances(mass_grid(),dicts)

    for (dname,d) in dicts.iteritems():
        print dname,d

if False:
    J7503_Dict = SignalDictionaries.dataLikeHists_J7503.copy()
    J7506_Dict = SignalDictionaries.dataLikeHists_J7506.copy()
    J10006_Dict = SignalDictionaries.dataLikeHists_J10006.copy()
    # interpolate systematic-varied acceptances
    #fit_normalizations('7503',J7503_Dict)
    fit_normalizations('10006',J10006_Dict)
    #test_normalizations('7503',J7503_Dict)
    #test_normalizations_syst('7503',J7503_Dict)


# morph signal templates


if False:
    # do missing templates in a non-Linear morph mode
    tryNonlinearMorphs = True
    savePlots = True
    unbiasedTest = False
    for selection in [ '7503' , '10006' ]:
        inputs = load_inputs(selection)
        allcouplings = get_list_of_couplings(inputs)
        for coupling in allcouplings:
            #outputMasses = [ 0.6 , 0.85 , 1.05 , 1.1 , 1.8 ]
            outputMasses = [ 0.85 , 1.05 , 1.1 ]
            allsystematics = get_list_of_systematics(inputs)
            for systematic in ['Nominal']: #allsystematics: # ['Nominal']: 
                for variation in get_list_of_systematic_variations(inputs,systematic):
                    morph(inputs,dicts,selection,coupling,systematic,variation,outputMasses,savePlots,unbiasedTest)
    exit()

if True:
    #for selection in ['7503','10006']:
    selection = str(sys.argv[1])
    coupling = str(sys.argv[2])
    print "SELECTION is %s and COUPLING is %s" % (selection,coupling)

    if selection not in ['7503','7506','10006']:
        print "FATAL: first argument to this script should be either 7503 or 10006"
        exit()
    inputs = load_inputs(selection)
    allcouplings = get_list_of_couplings(inputs)
    print allcouplings
    if coupling not in allcouplings:
        print "FATAL: second argument to this script should be a valid coupling"
        exit()
    
    allsystematics = get_list_of_systematics(inputs)
    for systematic in allsystematics: #['Nominal']: 
        for variation in get_list_of_systematic_variations(inputs,systematic):
            outputMasses = mass_grid()
            savePlots = False
            unbiasedTest = True
            morph_modified_2_14(inputs,dicts,selection,coupling,systematic,variation,outputMasses,savePlots,unbiasedTest)

# investigate
# why m=1.6 samples appear at 0.8 tev for g=0.05, 0.15

# print list of sample and coupling pairs to process in parallel
if False:
    for selection in ['7503','7506','10006']:
        inputs = load_inputs(selection)
        for coupling in get_list_of_couplings(inputs):
            print "%s %s" % (selection,coupling)

# test binning            
if False:
    inputs = load_inputs('7503')
    (h,hname) = inputs['0.05']['0.75']['Nominal']['0']
    print hname
    rebinh = rebin_unitGeV_histogram(h)
    for i in range(0,rebinh.GetNbinsX()+1):
        print i, rebinh.GetBinLowEdge(i), rebinh.GetBinLowEdge(i)+rebinh.GetBinWidth(i)
