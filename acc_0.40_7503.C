void acc_0.40_7503()
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
   
   TH2D *frame__17 = new TH2D("frame__17","",10,0,4,10,0.01,1);
   
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
   frame__17->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__17);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__17->SetLineColor(ci);
   frame__17->GetXaxis()->SetLabelFont(42);
   frame__17->GetXaxis()->SetLabelSize(0.035);
   frame__17->GetXaxis()->SetTitleSize(0.035);
   frame__17->GetXaxis()->SetTitleFont(42);
   frame__17->GetYaxis()->SetLabelFont(42);
   frame__17->GetYaxis()->SetLabelSize(0.035);
   frame__17->GetYaxis()->SetTitleSize(0.035);
   frame__17->GetYaxis()->SetTitleOffset(0);
   frame__17->GetYaxis()->SetTitleFont(42);
   frame__17->GetZaxis()->SetLabelFont(42);
   frame__17->GetZaxis()->SetLabelSize(0.035);
   frame__17->GetZaxis()->SetTitleSize(0.035);
   frame__17->GetZaxis()->SetTitleFont(42);
   frame__17->Draw("");
   
   Double_t _fx33[8] = {
   0.65,
   0.75,
   1.15,
   1.05,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy33[8] = {
   0.205,
   0.218,
   0.228,
   0.232,
   0.227,
   0.232,
   0.223,
   0.212};
   TGraph *graph = new TGraph(8,_fx33,_fy33);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph33 = new TH1F("Graph_Graph33","",100,0.515,2.135);
   Graph_Graph33->SetMinimum(0.2023);
   Graph_Graph33->SetMaximum(0.2347);
   Graph_Graph33->SetDirectory(0);
   Graph_Graph33->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph33->SetLineColor(ci);
   Graph_Graph33->GetXaxis()->SetLabelFont(42);
   Graph_Graph33->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph33->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph33->GetXaxis()->SetTitleFont(42);
   Graph_Graph33->GetYaxis()->SetLabelFont(42);
   Graph_Graph33->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph33->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph33->GetYaxis()->SetTitleOffset(0);
   Graph_Graph33->GetYaxis()->SetTitleFont(42);
   Graph_Graph33->GetZaxis()->SetLabelFont(42);
   Graph_Graph33->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph33->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph33->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph33);
   
   
   TF1 *mp34 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp34->SetFillColor(19);
   mp34->SetFillStyle(0);
   mp34->SetLineColor(2);
   mp34->SetLineWidth(2);
   mp34->SetChisquare(0.0003066786);
   mp34->SetNDF(3);
   mp34->GetXaxis()->SetLabelFont(42);
   mp34->GetXaxis()->SetLabelSize(0.035);
   mp34->GetXaxis()->SetTitleSize(0.035);
   mp34->GetXaxis()->SetTitleFont(42);
   mp34->GetYaxis()->SetLabelFont(42);
   mp34->GetYaxis()->SetLabelSize(0.035);
   mp34->GetYaxis()->SetTitleSize(0.035);
   mp34->GetYaxis()->SetTitleOffset(0);
   mp34->GetYaxis()->SetTitleFont(42);
   mp34->SetParameter(0,0.2247727);
   mp34->SetParError(0,0.003152399);
   mp34->SetParLimits(0,0,0.4);
   mp34->SetParameter(1,0.5339324);
   mp34->SetParError(1,0.01528944);
   mp34->SetParLimits(1,0,2);
   mp34->SetParameter(2,19.90074);
   mp34->SetParError(2,0.1108636);
   mp34->SetParLimits(2,5,20);
   mp34->SetParameter(3,19.5382);
   mp34->SetParError(3,0.1762772);
   mp34->SetParLimits(3,1,20);
   mp34->SetParameter(4,-34.73859);
   mp34->SetParError(4,0.8084156);
   mp34->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp34);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
