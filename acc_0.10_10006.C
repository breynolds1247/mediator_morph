void acc_0.10_10006()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 12 18:15:33 2017) by ROOT version6.10/08
   TCanvas *c1 = new TCanvas("c1", "c1",10,44,700,500);
   gStyle->SetOptFit(1);
   c1->SetHighLightColor(2);
   c1->Range(-0.5,-0.11375,4.5,1.12375);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2D *frame__8 = new TH2D("frame__8","",10,0,4,10,0.01,1);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("frame");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 0      ");
   ptstats_LaTex = ptstats->AddText("Mean x =      0");
   ptstats_LaTex = ptstats->AddText("Mean y =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev x =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(11111);
   ptstats->Draw();
   frame__8->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__8);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__8->SetLineColor(ci);
   frame__8->GetXaxis()->SetLabelFont(42);
   frame__8->GetXaxis()->SetLabelSize(0.035);
   frame__8->GetXaxis()->SetTitleSize(0.035);
   frame__8->GetXaxis()->SetTitleFont(42);
   frame__8->GetYaxis()->SetLabelFont(42);
   frame__8->GetYaxis()->SetLabelSize(0.035);
   frame__8->GetYaxis()->SetTitleSize(0.035);
   frame__8->GetYaxis()->SetTitleOffset(0);
   frame__8->GetYaxis()->SetTitleFont(42);
   frame__8->GetZaxis()->SetLabelFont(42);
   frame__8->GetZaxis()->SetLabelSize(0.035);
   frame__8->GetZaxis()->SetTitleSize(0.035);
   frame__8->GetZaxis()->SetTitleFont(42);
   frame__8->Draw("");
   
   Double_t _fx15[11] = {
   0.65,
   0.75,
   0.45,
   0.55,
   1,
   0.35,
   1.5,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy15[11] = {
   0.335,
   0.405,
   0.01,
   0.16,
   0.459,
   0.006,
   0.467,
   0.469,
   0.437,
   0.448,
   0.464};
   TGraph *graph = new TGraph(11,_fx15,_fy15);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph15 = new TH1F("Graph_Graph15","",100,0.185,2.165);
   Graph_Graph15->SetMinimum(0.0054);
   Graph_Graph15->SetMaximum(0.5153);
   Graph_Graph15->SetDirectory(0);
   Graph_Graph15->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph15->SetLineColor(ci);
   Graph_Graph15->GetXaxis()->SetLabelFont(42);
   Graph_Graph15->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetXaxis()->SetTitleFont(42);
   Graph_Graph15->GetYaxis()->SetLabelFont(42);
   Graph_Graph15->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetYaxis()->SetTitleOffset(0);
   Graph_Graph15->GetYaxis()->SetTitleFont(42);
   Graph_Graph15->GetZaxis()->SetLabelFont(42);
   Graph_Graph15->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph15);
   
   
   TF1 *mp16 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp16->SetFillColor(19);
   mp16->SetFillStyle(0);
   mp16->SetLineColor(2);
   mp16->SetLineWidth(2);
   mp16->SetChisquare(0.001929327);
   mp16->SetNDF(5);
   mp16->GetXaxis()->SetLabelFont(42);
   mp16->GetXaxis()->SetLabelSize(0.035);
   mp16->GetXaxis()->SetTitleSize(0.035);
   mp16->GetXaxis()->SetTitleFont(42);
   mp16->GetYaxis()->SetLabelFont(42);
   mp16->GetYaxis()->SetLabelSize(0.035);
   mp16->GetYaxis()->SetTitleSize(0.035);
   mp16->GetYaxis()->SetTitleOffset(0);
   mp16->GetYaxis()->SetTitleFont(42);
   mp16->SetParameter(0,0.2281529);
   mp16->SetParError(0,6.105042e-05);
   mp16->SetParLimits(0,0,0.6);
   mp16->SetParameter(1,0.5932376);
   mp16->SetParError(1,0.0001385951);
   mp16->SetParLimits(1,0,2);
   mp16->SetParameter(2,16.81836);
   mp16->SetParError(2,0.03454615);
   mp16->SetParLimits(2,5,20);
   mp16->SetParameter(3,13.31165);
   mp16->SetParError(3,0.2461898);
   mp16->SetParLimits(3,1,20);
   mp16->SetParameter(4,-5.904655e-06);
   mp16->SetParError(4,0.002547434);
   mp16->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp16);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
