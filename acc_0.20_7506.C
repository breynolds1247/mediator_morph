void acc_0.20_7506()
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
   
   TH2D *frame__4 = new TH2D("frame__4","",10,0,4,10,0.01,1);
   
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
   frame__4->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__4);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__4->SetLineColor(ci);
   frame__4->GetXaxis()->SetLabelFont(42);
   frame__4->GetXaxis()->SetLabelSize(0.035);
   frame__4->GetXaxis()->SetTitleSize(0.035);
   frame__4->GetXaxis()->SetTitleFont(42);
   frame__4->GetYaxis()->SetLabelFont(42);
   frame__4->GetYaxis()->SetLabelSize(0.035);
   frame__4->GetYaxis()->SetTitleSize(0.035);
   frame__4->GetYaxis()->SetTitleOffset(0);
   frame__4->GetYaxis()->SetTitleFont(42);
   frame__4->GetZaxis()->SetLabelFont(42);
   frame__4->GetZaxis()->SetLabelSize(0.035);
   frame__4->GetZaxis()->SetTitleSize(0.035);
   frame__4->GetZaxis()->SetTitleFont(42);
   frame__4->Draw("");
   
   Double_t _fx7[10] = {
   0.65,
   0.75,
   0.45,
   0.55,
   1,
   1.5,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy7[10] = {
   0.41,
   0.443,
   0.122,
   0.35,
   0.467,
   0.467,
   0.469,
   0.465,
   0.467,
   0.455};
   TGraph *graph = new TGraph(10,_fx7,_fy7);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph7 = new TH1F("Graph_Graph7","",100,0.295,2.155);
   Graph_Graph7->SetMinimum(0.0873);
   Graph_Graph7->SetMaximum(0.5037);
   Graph_Graph7->SetDirectory(0);
   Graph_Graph7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph7->SetLineColor(ci);
   Graph_Graph7->GetXaxis()->SetLabelFont(42);
   Graph_Graph7->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetXaxis()->SetTitleFont(42);
   Graph_Graph7->GetYaxis()->SetLabelFont(42);
   Graph_Graph7->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetYaxis()->SetTitleOffset(0);
   Graph_Graph7->GetYaxis()->SetTitleFont(42);
   Graph_Graph7->GetZaxis()->SetLabelFont(42);
   Graph_Graph7->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph7);
   
   
   TF1 *mp8 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))",0.5,1.8);
   mp8->SetFillColor(19);
   mp8->SetFillStyle(0);
   mp8->SetLineColor(2);
   mp8->SetLineWidth(2);
   mp8->SetChisquare(5.198142e-05);
   mp8->SetNDF(5);
   mp8->GetXaxis()->SetLabelFont(42);
   mp8->GetXaxis()->SetLabelSize(0.035);
   mp8->GetXaxis()->SetTitleSize(0.035);
   mp8->GetXaxis()->SetTitleFont(42);
   mp8->GetYaxis()->SetLabelFont(42);
   mp8->GetYaxis()->SetLabelSize(0.035);
   mp8->GetYaxis()->SetTitleSize(0.035);
   mp8->GetYaxis()->SetTitleOffset(0);
   mp8->GetYaxis()->SetTitleFont(42);
   mp8->SetParameter(0,0.469792);
   mp8->SetParError(0,0.001735872);
   mp8->SetParLimits(0,0,0);
   mp8->SetParameter(1,0.431696);
   mp8->SetParError(1,0.008781707);
   mp8->SetParLimits(1,0,0);
   mp8->SetParameter(2,8.975457);
   mp8->SetParError(2,0.5363831);
   mp8->SetParLimits(2,0,0);
   graph->GetListOfFunctions()->Add(mp8);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
