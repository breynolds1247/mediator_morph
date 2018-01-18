void acc_0.05_7506()
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
   
   TH2D *frame__3 = new TH2D("frame__3","",10,0,4,10,0.01,1);
   
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
   frame__3->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__3);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__3->SetLineColor(ci);
   frame__3->GetXaxis()->SetLabelFont(42);
   frame__3->GetXaxis()->SetLabelSize(0.035);
   frame__3->GetXaxis()->SetTitleSize(0.035);
   frame__3->GetXaxis()->SetTitleFont(42);
   frame__3->GetYaxis()->SetLabelFont(42);
   frame__3->GetYaxis()->SetLabelSize(0.035);
   frame__3->GetYaxis()->SetTitleSize(0.035);
   frame__3->GetYaxis()->SetTitleOffset(0);
   frame__3->GetYaxis()->SetTitleFont(42);
   frame__3->GetZaxis()->SetLabelFont(42);
   frame__3->GetZaxis()->SetLabelSize(0.035);
   frame__3->GetZaxis()->SetTitleSize(0.035);
   frame__3->GetZaxis()->SetTitleFont(42);
   frame__3->Draw("");
   
   Double_t _fx5[6] = {
   0.65,
   0.75,
   0.85,
   0.95,
   0.45,
   0.55};
   Double_t _fy5[6] = {
   0.419,
   0.448,
   0.455,
   0.464,
   0.12,
   0.341};
   TGraph *graph = new TGraph(6,_fx5,_fy5);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","",100,0.4,1);
   Graph_Graph5->SetMinimum(0.0856);
   Graph_Graph5->SetMaximum(0.4984);
   Graph_Graph5->SetDirectory(0);
   Graph_Graph5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph5->SetLineColor(ci);
   Graph_Graph5->GetXaxis()->SetLabelFont(42);
   Graph_Graph5->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetYaxis()->SetTitleOffset(0);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph5);
   
   
   TF1 *mp6 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp6->SetFillColor(19);
   mp6->SetFillStyle(0);
   mp6->SetLineColor(2);
   mp6->SetLineWidth(2);
   mp6->SetChisquare(0.0003720527);
   mp6->SetNDF(1);
   mp6->GetXaxis()->SetLabelFont(42);
   mp6->GetXaxis()->SetLabelSize(0.035);
   mp6->GetXaxis()->SetTitleSize(0.035);
   mp6->GetXaxis()->SetTitleFont(42);
   mp6->GetYaxis()->SetLabelFont(42);
   mp6->GetYaxis()->SetLabelSize(0.035);
   mp6->GetYaxis()->SetTitleSize(0.035);
   mp6->GetYaxis()->SetTitleOffset(0);
   mp6->GetYaxis()->SetTitleFont(42);
   mp6->SetParameter(0,0.4535658);
   mp6->SetParError(0,0.009289318);
   mp6->SetParLimits(0,0,0);
   mp6->SetParameter(1,0.4988144);
   mp6->SetParError(1,0.007783124);
   mp6->SetParLimits(1,0,0);
   mp6->SetParameter(2,20.18264);
   mp6->SetParError(2,0.0272772);
   mp6->SetParLimits(2,0,0);
   mp6->SetParameter(3,12.28708);
   mp6->SetParError(3,0.2866744);
   mp6->SetParLimits(3,1,20);
   mp6->SetParameter(4,-1.044457);
   mp6->SetParError(4,1.459795);
   mp6->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp6);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
