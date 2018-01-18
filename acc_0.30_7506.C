void acc_0.30_7506()
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
   
   TH2D *frame__6 = new TH2D("frame__6","",10,0,4,10,0.01,1);
   
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
   frame__6->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__6);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__6->SetLineColor(ci);
   frame__6->GetXaxis()->SetLabelFont(42);
   frame__6->GetXaxis()->SetLabelSize(0.035);
   frame__6->GetXaxis()->SetTitleSize(0.035);
   frame__6->GetXaxis()->SetTitleFont(42);
   frame__6->GetYaxis()->SetLabelFont(42);
   frame__6->GetYaxis()->SetLabelSize(0.035);
   frame__6->GetYaxis()->SetTitleSize(0.035);
   frame__6->GetYaxis()->SetTitleOffset(0);
   frame__6->GetYaxis()->SetTitleFont(42);
   frame__6->GetZaxis()->SetLabelFont(42);
   frame__6->GetZaxis()->SetLabelSize(0.035);
   frame__6->GetZaxis()->SetTitleSize(0.035);
   frame__6->GetZaxis()->SetTitleFont(42);
   frame__6->Draw("");
   
   Double_t _fx11[11] = {
   0.65,
   0.75,
   0.45,
   0.55,
   1,
   1.05,
   1.5,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy11[11] = {
   0.402,
   0.433,
   0.122,
   0.33,
   0.463,
   0.467,
   0.474,
   0.469,
   0.458,
   0.46,
   0.45};
   TGraph *graph = new TGraph(11,_fx11,_fy11);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph11 = new TH1F("Graph_Graph11","",100,0.295,2.155);
   Graph_Graph11->SetMinimum(0.0868);
   Graph_Graph11->SetMaximum(0.5092);
   Graph_Graph11->SetDirectory(0);
   Graph_Graph11->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph11->SetLineColor(ci);
   Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph11->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph11->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetYaxis()->SetTitleOffset(0);
   Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph11->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph11);
   
   
   TF1 *mp12 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp12->SetFillColor(19);
   mp12->SetFillStyle(0);
   mp12->SetLineColor(2);
   mp12->SetLineWidth(2);
   mp12->SetChisquare(0.00162043);
   mp12->SetNDF(6);
   mp12->GetXaxis()->SetLabelFont(42);
   mp12->GetXaxis()->SetLabelSize(0.035);
   mp12->GetXaxis()->SetTitleSize(0.035);
   mp12->GetXaxis()->SetTitleFont(42);
   mp12->GetYaxis()->SetLabelFont(42);
   mp12->GetYaxis()->SetLabelSize(0.035);
   mp12->GetYaxis()->SetTitleSize(0.035);
   mp12->GetYaxis()->SetTitleOffset(0);
   mp12->GetYaxis()->SetTitleFont(42);
   mp12->SetParameter(0,0.4594238);
   mp12->SetParError(0,0.006130218);
   mp12->SetParLimits(0,0,0);
   mp12->SetParameter(1,0.504667);
   mp12->SetParError(1,0.007318783);
   mp12->SetParLimits(1,0,0);
   mp12->SetParameter(2,16.55078);
   mp12->SetParError(2,2.31063);
   mp12->SetParLimits(2,0,0);
   mp12->SetParameter(3,3.068667);
   mp12->SetParError(3,0.2862544);
   mp12->SetParLimits(3,1,20);
   mp12->SetParameter(4,-7.6208);
   mp12->SetParError(4,0.8364339);
   mp12->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp12);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
