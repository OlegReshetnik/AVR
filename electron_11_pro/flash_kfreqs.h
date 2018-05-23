#ifndef flash_kfreqs_h
#define flash_kfreqs_h

#include <avr/pgmspace.h>
#include <stdint.h>

#define K_S( a )	( (uint8_t)( sizeof( a ) / sizeof( a[0] ) ) )
#define K_P( x )	( (uint16_t)&x[0] )
#define K_K( x )	( (uint32_t)( x * 100.0 ) )


//******************************************
const uint8_t kpg_01[] PROGMEM = "œÀ≈—≈Õ‹";

const uint8_t kn01_01[] PROGMEM = "Aflatoxin";
const uint32_t kf01_01[] PROGMEM = { K_K(177190.00) };
#define KL01_01 ( 1200 )

const uint8_t kn01_02[] PROGMEM = "Besnoitia prot";
const uint32_t kf01_02[] PROGMEM = { 
K_K(352800.00), K_K(353755.56), K_K(354711.11), K_K(355666.67), 
K_K(356622.22), K_K(357577.78), K_K(358533.33), K_K(359488.89), 
K_K(360444.44), K_K(361400.00) };
#define KL01_02 ( 120 )

const uint8_t kn01_03[] PROGMEM = "Cytochalasin ¬";
const uint32_t kf01_03[] PROGMEM = { K_K(77000.00) };
#define KL01_03 ( 1200 )

const uint8_t kn01_04[] PROGMEM = "Cytochalasin ¬2";
const uint32_t kf01_04[] PROGMEM = { K_K(91000.00) };
#define KL01_04 ( 1200 )

const uint8_t kn01_05[] PROGMEM = "Ergot";
const uint32_t kf01_05[] PROGMEM = { K_K(295000.00) };
#define KL01_05 ( 1200 )

const uint8_t kn01_06[] PROGMEM = "Griseofulvin";
const uint32_t kf01_06[] PROGMEM = { K_K(288000.00) };
#define KL01_06 ( 1200 )

const uint8_t kn01_07[] PROGMEM = "Histoplasma cap";
const uint32_t kf01_07[] PROGMEM = { 
K_K(298300.00), K_K(299027.78), K_K(299755.56), K_K(300483.33), 
K_K(301211.11), K_K(301938.89), K_K(302666.67), K_K(303394.44), 
K_K(304122.22), K_K(304850.00) };
#define KL01_07 ( 120 )

const uint8_t kn01_08[] PROGMEM = "Myxosoma";
const uint32_t kf01_08[] PROGMEM = { 
K_K(409600.00), K_K(410416.67), K_K(411233.33), K_K(412050.00), 
K_K(412866.67), K_K(413683.33), K_K(414500.00), K_K(415316.67), 
K_K(416133.33), K_K(416950.00) };
#define KL01_08 ( 120 )

const uint8_t kn01_09[] PROGMEM = "Pneumocystis c.";
const uint32_t kf01_09[] PROGMEM = { 
K_K(405750.00), K_K(406127.78), K_K(406505.56), K_K(406883.33), 
K_K(407261.11), K_K(407638.89), K_K(408016.67), K_K(408394.44), 
K_K(408772.22), K_K(409150.00) };
#define KL01_09 ( 120 )

const uint8_t kn01_10[] PROGMEM = "Sorghum syrup";
const uint32_t kf01_10[] PROGMEM = { K_K(277000.00) };
#define KL01_10 ( 1200 )

const uint8_t kn01_11[] PROGMEM = "Sterigmatocyst.";
const uint32_t kf01_11[] PROGMEM = { K_K(88000.00) };
#define KL01_11 ( 1200 )

const uint8_t kn01_12[] PROGMEM = "Sterigmatocyst2";
const uint32_t kf01_12[] PROGMEM = { K_K(96000.00) };
#define KL01_12 ( 1200 )

const uint8_t kn01_13[] PROGMEM = "Sterigmatocyst3";
const uint32_t kf01_13[] PROGMEM = { K_K(133000.00) };
#define KL01_13 ( 1200 )

const uint8_t kn01_14[] PROGMEM = "Sterigmatocyst4";
const uint32_t kf01_14[] PROGMEM = { K_K(126000.00) };
#define KL01_14 ( 1200 )

const uint8_t kn01_15[] PROGMEM = "Zearalenone";
const uint32_t kf01_15[] PROGMEM = { K_K(100000.00) };
#define KL01_15 ( 1200 )

const uint8_t * const kpg_n01[] PROGMEM = { 
kn01_01, kn01_02, kn01_03, kn01_04, kn01_05, kn01_06, kn01_07, kn01_08, 
kn01_09, kn01_10, kn01_11, kn01_12, kn01_13, kn01_14, kn01_15, (uint8_t *)0 };
const uint32_t * const kpg_f01[] PROGMEM = { 
kf01_01, kf01_02, kf01_03, kf01_04, kf01_05, kf01_06, kf01_07, kf01_08, 
kf01_09, kf01_10, kf01_11, kf01_12, kf01_13, kf01_14, kf01_15 };
const uint8_t kpg_j01[] PROGMEM = { 
K_S(kf01_01), K_S(kf01_02), K_S(kf01_03), K_S(kf01_04), K_S(kf01_05), K_S(kf01_06), K_S(kf01_07), K_S(kf01_08), 
K_S(kf01_09), K_S(kf01_10), K_S(kf01_11), K_S(kf01_12), K_S(kf01_13), K_S(kf01_14), K_S(kf01_15) };
const uint16_t kpg_t01[] PROGMEM = { 
KL01_01, KL01_02, KL01_03, KL01_04, KL01_05, KL01_06, KL01_07, KL01_08, 
KL01_09, KL01_10, KL01_11, KL01_12, KL01_13, KL01_14, KL01_15 };

//******************************************
const uint8_t kpg_02[] PROGMEM = "—À»«»—“.œÀ≈—≈Õ‹";

const uint8_t kn02_01[] PROGMEM = "Arcyria";
const uint32_t kf02_01[] PROGMEM = { K_K(81000.00) };
#define KL02_01 ( 1200 )

const uint8_t kn02_02[] PROGMEM = "Lycogala";
const uint32_t kf02_02[] PROGMEM = { K_K(126000.00) };
#define KL02_02 ( 1200 )

const uint8_t kn02_03[] PROGMEM = "Stemonitis";
const uint32_t kf02_03[] PROGMEM = { K_K(211000.00) };
#define KL02_03 ( 1200 )

const uint8_t * const kpg_n02[] PROGMEM = { kn02_01, kn02_02, kn02_03, (uint8_t *)0 };
const uint32_t * const kpg_f02[] PROGMEM = { kf02_01, kf02_02, kf02_03 };
const uint8_t kpg_j02[] PROGMEM = { K_S(kf02_01), K_S(kf02_02), K_S(kf02_03) };
const uint16_t kpg_t02[] PROGMEM = { KL02_01, KL02_02, KL02_03 };

//******************************************
const uint8_t kpg_03[] PROGMEM = "ƒ–Œ∆∆»";

const uint8_t kn03_01[] PROGMEM = "Candida albican";
const uint32_t kf03_01[] PROGMEM = { 
K_K(384200.00), K_K(384666.67), K_K(385133.33), K_K(385600.00), 
K_K(386066.67), K_K(386533.33), K_K(387000.00), K_K(387466.67), 
K_K(387933.33), K_K(388400.00) };
#define KL03_01 ( 120 )

const uint8_t * const kpg_n03[] PROGMEM = { kn03_01, (uint8_t *)0 };
const uint32_t * const kpg_f03[] PROGMEM = { kf03_01 };
const uint8_t kpg_j03[] PROGMEM = { K_S(kf03_01) };
const uint16_t kpg_t03[] PROGMEM = { KL03_01 };

//******************************************
const uint8_t kpg_04[] PROGMEM = "¬»–”—€";

const uint8_t kn04_01[] PROGMEM = "Adenovirus";
const uint32_t kf04_01[] PROGMEM = { K_K(393000.00) };
#define KL04_01 ( 1200 )

const uint8_t kn04_02[] PROGMEM = "Adenovirus 2nd";
const uint32_t kf04_02[] PROGMEM = { 
K_K(371450.00), K_K(373166.67), K_K(374883.33), K_K(376600.00), 
K_K(378316.67), K_K(380033.33), K_K(381750.00), K_K(383466.67), 
K_K(385183.33), K_K(386900.00) };
#define KL04_02 ( 120 )

const uint8_t kn04_03[] PROGMEM = "Coxsackie B1";
const uint32_t kf04_03[] PROGMEM = { 
K_K(360500.00), K_K(361122.22), K_K(361744.44), K_K(362366.67), 
K_K(362988.89), K_K(363611.11), K_K(364233.33), K_K(364855.56), 
K_K(365477.78), K_K(366100.00) };
#define KL04_03 ( 120 )

const uint8_t kn04_04[] PROGMEM = "Coxsackie B4";
const uint32_t kf04_04[] PROGMEM = { 
K_K(361450.00), K_K(361700.00), K_K(361950.00), K_K(362200.00), 
K_K(362450.00), K_K(362700.00), K_K(362950.00), K_K(363200.00), 
K_K(363450.00), K_K(363700.00) };
#define KL04_04 ( 120 )

const uint8_t kn04_05[] PROGMEM = "Coxsackie B4 2";
const uint32_t kf04_05[] PROGMEM = { 
K_K(363900.00), K_K(364011.11), K_K(364122.22), K_K(364233.33), 
K_K(364344.44), K_K(364455.56), K_K(364566.67), K_K(364677.78), 
K_K(364788.89), K_K(364900.00) };
#define KL04_05 ( 120 )

const uint8_t kn04_06[] PROGMEM = "Cytomegalovirus";
const uint32_t kf04_06[] PROGMEM = { 
K_K(408350.00), K_K(408616.67), K_K(408883.33), K_K(409150.00), 
K_K(409416.67), K_K(409683.33), K_K(409950.00), K_K(410216.67), 
K_K(410483.33), K_K(410750.00) };
#define KL04_06 ( 120 )

const uint8_t kn04_07[] PROGMEM = "Epstein Barre";
const uint32_t kf04_07[] PROGMEM = { 
K_K(372500.00), K_K(373650.00), K_K(374800.00), K_K(375950.00), 
K_K(377100.00), K_K(378250.00), K_K(379400.00), K_K(380550.00), 
K_K(381700.00), K_K(382850.00) };
#define KL04_07 ( 120 )

const uint8_t kn04_08[] PROGMEM = "Hepatitis ¬";
const uint32_t kf04_08[] PROGMEM = { 
K_K(414550.00), K_K(415244.44), K_K(415938.89), K_K(416633.33), 
K_K(417327.78), K_K(418022.22), K_K(418716.67), K_K(419411.11), 
K_K(420105.56), K_K(420800.00) };
#define KL04_08 ( 120 )

const uint8_t kn04_09[] PROGMEM = "Herpes simplex1";
const uint32_t kf04_09[] PROGMEM = { 
K_K(291250.00), K_K(291450.00), K_K(291650.00), K_K(291850.00), 
K_K(292050.00), K_K(292250.00), K_K(292450.00), K_K(292650.00), 
K_K(292850.00), K_K(293050.00) };
#define KL04_09 ( 120 )

const uint8_t kn04_10[] PROGMEM = "Herpes simp.1";
const uint32_t kf04_10[] PROGMEM = { 
K_K(2.00), K_K(38374.00), K_K(76746.00), K_K(115118.00), 
K_K(153490.00), K_K(191862.00), K_K(230234.00), K_K(268606.00), 
K_K(306978.00), K_K(345350.00) };
#define KL04_10 ( 120 )

const uint8_t kn04_11[] PROGMEM = "Herpes simplex2";
const uint32_t kf04_11[] PROGMEM = { 
K_K(353900.00), K_K(354900.00), K_K(355900.00), K_K(356900.00), 
K_K(357900.00), K_K(358900.00), K_K(359900.00), K_K(360900.00), 
K_K(361900.00), K_K(362900.00) };
#define KL04_11 ( 120 )

const uint8_t kn04_12[] PROGMEM = "Herpes Zoster";
const uint32_t kf04_12[] PROGMEM = { 
K_K(416600.00), K_K(417000.00), K_K(417400.00), K_K(417800.00), 
K_K(418200.00), K_K(418600.00), K_K(419000.00), K_K(419400.00), 
K_K(419800.00), K_K(420200.00) };
#define KL04_12 ( 120 )

const uint8_t kn04_13[] PROGMEM = "Influenza A&¬";
const uint32_t kf04_13[] PROGMEM = { 
K_K(313350.00), K_K(314522.22), K_K(315694.44), K_K(316866.67), 
K_K(318038.89), K_K(319211.11), K_K(320383.33), K_K(321555.56), 
K_K(322727.78), K_K(323900.00) };
#define KL04_13 ( 120 )

const uint8_t kn04_14[] PROGMEM = "Measles antigen";
const uint32_t kf04_14[] PROGMEM = { 
K_K(369500.00), K_K(369888.89), K_K(370277.78), K_K(370666.67), 
K_K(371055.56), K_K(371444.44), K_K(371833.33), K_K(372222.22), 
K_K(372611.11), K_K(373000.00) };
#define KL04_14 ( 120 )

const uint8_t kn04_15[] PROGMEM = "Mumps antigen";
const uint32_t kf04_15[] PROGMEM = { 
K_K(377600.00), K_K(378383.33), K_K(379166.67), K_K(379950.00), 
K_K(380733.33), K_K(381516.67), K_K(382300.00), K_K(383083.33), 
K_K(383866.67), K_K(384650.00) };
#define KL04_15 ( 120 )

const uint8_t kn04_16[] PROGMEM = "Respiratory syn";
const uint32_t kf04_16[] PROGMEM = { 
K_K(378950.00), K_K(379416.67), K_K(379883.33), K_K(380350.00), 
K_K(380816.67), K_K(381283.33), K_K(381750.00), K_K(382216.67), 
K_K(382683.33), K_K(383150.00) };
#define KL04_16 ( 120 )

const uint8_t kn04_17[] PROGMEM = "Tobacco mosaic";
const uint32_t kf04_17[] PROGMEM = { 
K_K(427150.00), K_K(427416.67), K_K(427683.33), K_K(427950.00), 
K_K(428216.67), K_K(428483.33), K_K(428750.00), K_K(429016.67), 
K_K(429283.33), K_K(429550.00) };
#define KL04_17 ( 120 )

const uint8_t * const kpg_n04[] PROGMEM = { 
kn04_01, kn04_02, kn04_03, kn04_04, kn04_05, kn04_06, kn04_07, kn04_08, 
kn04_09, kn04_10, kn04_11, kn04_12, kn04_13, kn04_14, kn04_15, kn04_16, kn04_17, (uint8_t *)0 };
const uint32_t * const kpg_f04[] PROGMEM = { 
kf04_01, kf04_02, kf04_03, kf04_04, kf04_05, kf04_06, kf04_07, kf04_08, 
kf04_09, kf04_10, kf04_11, kf04_12, kf04_13, kf04_14, kf04_15, kf04_16, kf04_17 };
const uint8_t kpg_j04[] PROGMEM = { 
K_S(kf04_01), K_S(kf04_02), K_S(kf04_03), K_S(kf04_04), K_S(kf04_05), K_S(kf04_06), K_S(kf04_07), K_S(kf04_08), 
K_S(kf04_09), K_S(kf04_10), K_S(kf04_11), K_S(kf04_12), K_S(kf04_13), K_S(kf04_14), K_S(kf04_15), K_S(kf04_16), K_S(kf04_17) };
const uint16_t kpg_t04[] PROGMEM = { 
KL04_01, KL04_02, KL04_03, KL04_04, KL04_05, KL04_06, KL04_07, KL04_08, 
KL04_09, KL04_10, KL04_11, KL04_12, KL04_13, KL04_14, KL04_15, KL04_16, KL04_17 };

//******************************************
const uint8_t kpg_05[] PROGMEM = "¡Œ–Œƒ¿¬ »";

const uint8_t kn05_01[] PROGMEM = "Wart BS";
const uint32_t kf05_01[] PROGMEM = { 
K_K(402000.00), K_K(402444.44), K_K(402888.89), K_K(403333.33), 
K_K(403777.78), K_K(404222.22), K_K(404666.67), K_K(405111.11), 
K_K(405555.56), K_K(406000.00) };
#define KL05_01 ( 120 )

const uint8_t kn05_02[] PROGMEM = "Wart HA";
const uint32_t kf05_02[] PROGMEM = { 
K_K(434800.00), K_K(435833.33), K_K(436866.67), K_K(437900.00), 
K_K(438933.33), K_K(439966.67), K_K(441000.00), K_K(442033.33), 
K_K(443066.67), K_K(444100.00) };
#define KL05_02 ( 120 )

const uint8_t kn05_03[] PROGMEM = "Papilloma pl";
const uint32_t kf05_03[] PROGMEM = { 
K_K(404700.00), K_K(404927.78), K_K(405155.56), K_K(405383.33), 
K_K(405611.11), K_K(405838.89), K_K(406066.67), K_K(406294.44), 
K_K(406522.22), K_K(406750.00) };
#define KL05_03 ( 120 )

const uint8_t kn05_04[] PROGMEM = "Papilloma vir";
const uint32_t kf05_04[] PROGMEM = { 
K_K(402850.00), K_K(403722.22), K_K(404594.44), K_K(405466.67), 
K_K(406338.89), K_K(407211.11), K_K(408083.33), K_K(408955.56), 
K_K(409827.78), K_K(410700.00) };
#define KL05_04 ( 120 )

const uint8_t kn05_05[] PROGMEM = "Wart L arm";
const uint32_t kf05_05[] PROGMEM = { 
K_K(343650.00), K_K(343905.56), K_K(344161.11), K_K(344416.67), 
K_K(344672.22), K_K(344927.78), K_K(345183.33), K_K(345438.89), 
K_K(345694.44), K_K(345950.00) };
#define KL05_05 ( 120 )

const uint8_t kn05_06[] PROGMEM = "Papilloma ce.sm";
const uint32_t kf05_06[] PROGMEM = { 
K_K(404050.00), K_K(404111.11), K_K(404172.22), K_K(404233.33), 
K_K(404294.44), K_K(404355.56), K_K(404416.67), K_K(404477.78), 
K_K(404538.89), K_K(404600.00) };
#define KL05_06 ( 120 )

const uint8_t kn05_07[] PROGMEM = "Wart CC";
const uint32_t kf05_07[] PROGMEM = { 
K_K(426000.00), K_K(426705.56), K_K(427411.11), K_K(428116.67), 
K_K(428822.22), K_K(429527.78), K_K(430233.33), K_K(430938.89), 
K_K(431644.44), K_K(432350.00) };
#define KL05_07 ( 120 )

const uint8_t kn05_08[] PROGMEM = "Wart FR";
const uint32_t kf05_08[] PROGMEM = { 
K_K(459300.00), K_K(459905.56), K_K(460511.11), K_K(461116.67), 
K_K(461722.22), K_K(462327.78), K_K(462933.33), K_K(463538.89), 
K_K(464144.44), K_K(464750.00) };
#define KL05_08 ( 120 )

const uint8_t kn05_09[] PROGMEM = "Wart HRCm";
const uint32_t kf05_09[] PROGMEM = { 
K_K(438900.00), K_K(439972.22), K_K(441044.44), K_K(442116.67), 
K_K(443188.89), K_K(444261.11), K_K(445333.33), K_K(446405.56), 
K_K(447477.78), K_K(448550.00) };
#define KL05_09 ( 120 )

const uint8_t kn05_10[] PROGMEM = "War JB";
const uint32_t kf05_10[] PROGMEM = { 
K_K(418750.00), K_K(419155.56), K_K(419561.11), K_K(419966.67), 
K_K(420372.22), K_K(420777.78), K_K(421183.33), K_K(421588.89), 
K_K(421994.44), K_K(422400.00) };
#define KL05_10 ( 120 )

const uint8_t * const kpg_n05[] PROGMEM = { 
kn05_01, kn05_02, kn05_03, kn05_04, kn05_05, kn05_06, kn05_07, kn05_08, 
kn05_09, kn05_10, (uint8_t *)0 };
const uint32_t * const kpg_f05[] PROGMEM = { 
kf05_01, kf05_02, kf05_03, kf05_04, kf05_05, kf05_06, kf05_07, kf05_08, 
kf05_09, kf05_10 };
const uint8_t kpg_j05[] PROGMEM = { 
K_S(kf05_01), K_S(kf05_02), K_S(kf05_03), K_S(kf05_04), K_S(kf05_05), K_S(kf05_06), K_S(kf05_07), K_S(kf05_08), 
K_S(kf05_09), K_S(kf05_10) };
const uint16_t kpg_t05[] PROGMEM = { 
KL05_01, KL05_02, KL05_03, KL05_04, KL05_05, KL05_06, KL05_07, KL05_08, 
KL05_09, KL05_10 };

//******************************************
const uint8_t kpg_06[] PROGMEM = "¡¿ “≈–»»";

const uint8_t kn06_01[] PROGMEM = "Anaplasma marg.";
const uint32_t kf06_01[] PROGMEM = { 
K_K(386400.00), K_K(386577.78), K_K(386755.56), K_K(386933.33), 
K_K(387111.11), K_K(387288.89), K_K(387466.67), K_K(387644.44), 
K_K(387822.22), K_K(388000.00) };
#define KL06_01 ( 120 )

const uint8_t kn06_02[] PROGMEM = "Anaplasma marg2";
const uint32_t kf06_02[] PROGMEM = { 
K_K(415300.00), K_K(416266.67), K_K(417233.33), K_K(418200.00), 
K_K(419166.67), K_K(420133.33), K_K(421100.00), K_K(422066.67), 
K_K(423033.33), K_K(424000.00) };
#define KL06_02 ( 120 )

const uint8_t kn06_03[] PROGMEM = "Alpha streptoco";
const uint32_t kf06_03[] PROGMEM = { 
K_K(369750.00), K_K(371488.89), K_K(373227.78), K_K(374966.67), 
K_K(376705.56), K_K(378444.44), K_K(380183.33), K_K(381922.22), 
K_K(383661.11), K_K(385400.00) };
#define KL06_03 ( 120 )

const uint8_t kn06_04[] PROGMEM = "Bac. anthracis";
const uint32_t kf06_04[] PROGMEM = { 
K_K(393500.00), K_K(394005.56), K_K(394511.11), K_K(395016.67), 
K_K(395522.22), K_K(396027.78), K_K(396533.33), K_K(397038.89), 
K_K(397544.44), K_K(398050.00) };
#define KL06_04 ( 120 )

const uint8_t kn06_05[] PROGMEM = "Bac. anthracis2";
const uint32_t kf06_05[] PROGMEM = { 
K_K(363200.00), K_K(363433.33), K_K(363666.67), K_K(363900.00), 
K_K(364133.33), K_K(364366.67), K_K(364600.00), K_K(364833.33), 
K_K(365066.67), K_K(365300.00) };
#define KL06_05 ( 120 )

const uint8_t kn06_06[] PROGMEM = "Bac. anthracis3";
const uint32_t kf06_06[] PROGMEM = { 
K_K(359400.00), K_K(360633.33), K_K(361866.67), K_K(363100.00), 
K_K(364333.33), K_K(365566.67), K_K(366800.00), K_K(368033.33), 
K_K(369266.67), K_K(370500.00) };
#define KL06_06 ( 120 )

const uint8_t kn06_07[] PROGMEM = "Bac. ant.spores";
const uint32_t kf06_07[] PROGMEM = { 
K_K(386950.00), K_K(387450.00), K_K(387950.00), K_K(388450.00), 
K_K(388950.00), K_K(389450.00), K_K(389950.00), K_K(390450.00), 
K_K(390950.00), K_K(391450.00) };
#define KL06_07 ( 120 )

const uint8_t kn06_08[] PROGMEM = "Bacillus cereus";
const uint32_t kf06_08[] PROGMEM = { 
K_K(373650.00), K_K(373894.44), K_K(374138.89), K_K(374383.33), 
K_K(374627.78), K_K(374872.22), K_K(375116.67), K_K(375361.11), 
K_K(375605.56), K_K(375850.00) };
#define KL06_08 ( 120 )

const uint8_t kn06_09[] PROGMEM = "Subtilis niger";
const uint32_t kf06_09[] PROGMEM = { 
K_K(371850.00), K_K(373544.44), K_K(375238.89), K_K(376933.33), 
K_K(378627.78), K_K(380322.22), K_K(382016.67), K_K(383711.11), 
K_K(385405.56), K_K(387100.00) };
#define KL06_09 ( 120 )

const uint8_t kn06_10[] PROGMEM = "Bact. capsules";
const uint32_t kf06_10[] PROGMEM = { 
K_K(416050.00), K_K(416350.00), K_K(416650.00), K_K(416950.00), 
K_K(417250.00), K_K(417550.00), K_K(417850.00), K_K(418150.00), 
K_K(418450.00), K_K(418750.00) };
#define KL06_10 ( 120 )

const uint8_t kn06_11[] PROGMEM = "Bact. capsul.2";
const uint32_t kf06_11[] PROGMEM = { 
K_K(357600.00), K_K(358133.33), K_K(358666.67), K_K(359200.00), 
K_K(359733.33), K_K(360266.67), K_K(360800.00), K_K(361333.33), 
K_K(361866.67), K_K(362400.00) };
#define KL06_11 ( 120 )

const uint8_t kn06_12[] PROGMEM = "Bact. fragilis";
const uint32_t kf06_12[] PROGMEM = { 
K_K(324300.00), K_K(324377.78), K_K(324455.56), K_K(324533.33), 
K_K(324611.11), K_K(324688.89), K_K(324766.67), K_K(324844.44), 
K_K(324922.22), K_K(325000.00) };
#define KL06_12 ( 120 )

const uint8_t kn06_13[] PROGMEM = "Bact. fragilis2";
const uint32_t kf06_13[] PROGMEM = { 
K_K(325700.00), K_K(325733.33), K_K(325766.67), K_K(325800.00), 
K_K(325833.33), K_K(325866.67), K_K(325900.00), K_K(325933.33), 
K_K(325966.67), K_K(326000.00) };
#define KL06_13 ( 120 )

const uint8_t kn06_14[] PROGMEM = "Beta streptococ";
const uint32_t kf06_14[] PROGMEM = { 
K_K(380600.00), K_K(381355.56), K_K(382111.11), K_K(382866.67), 
K_K(383622.22), K_K(384377.78), K_K(385133.33), K_K(385888.89), 
K_K(386644.44), K_K(387400.00) };
#define KL06_14 ( 120 )

const uint8_t kn06_15[] PROGMEM = "Bordetella pert";
const uint32_t kf06_15[] PROGMEM = { 
K_K(329850.00), K_K(330116.67), K_K(330383.33), K_K(330650.00), 
K_K(330916.67), K_K(331183.33), K_K(331450.00), K_K(331716.67), 
K_K(331983.33), K_K(332250.00) };
#define KL06_15 ( 120 )

const uint8_t kn06_16[] PROGMEM = "Borellia burgdo";
const uint32_t kf06_16[] PROGMEM = { 
K_K(378950.00), K_K(379288.89), K_K(379627.78), K_K(379966.67), 
K_K(380305.56), K_K(380644.44), K_K(380983.33), K_K(381322.22), 
K_K(381661.11), K_K(382000.00) };
#define KL06_16 ( 120 )

const uint8_t kn06_17[] PROGMEM = "Branhamella Nei";
const uint32_t kf06_17[] PROGMEM = { 
K_K(394900.00), K_K(395100.00), K_K(395300.00), K_K(395500.00), 
K_K(395700.00), K_K(395900.00), K_K(396100.00), K_K(396300.00), 
K_K(396500.00), K_K(396700.00) };
#define KL06_17 ( 120 )

const uint8_t kn06_18[] PROGMEM = "Camp fetus sme";
const uint32_t kf06_18[] PROGMEM = { 
K_K(365300.00), K_K(365888.89), K_K(366477.78), K_K(367066.67), 
K_K(367655.56), K_K(368244.44), K_K(368833.33), K_K(369422.22), 
K_K(370011.11), K_K(370600.00) };
#define KL06_18 ( 120 )

const uint8_t kn06_19[] PROGMEM = "Campy.pyloridis";
const uint32_t kf06_19[] PROGMEM = { 
K_K(352000.00), K_K(352577.78), K_K(353155.56), K_K(353733.33), 
K_K(354311.11), K_K(354888.89), K_K(355466.67), K_K(356044.44), 
K_K(356622.22), K_K(357200.00) };
#define KL06_19 ( 120 )

const uint8_t kn06_20[] PROGMEM = "Central spores";
const uint32_t kf06_20[] PROGMEM = { 
K_K(372450.00), K_K(373138.89), K_K(373827.78), K_K(374516.67), 
K_K(375205.56), K_K(375894.44), K_K(376583.33), K_K(377272.22), 
K_K(377961.11), K_K(378650.00) };
#define KL06_20 ( 120 )

const uint8_t kn06_21[] PROGMEM = "Chlamydia trach";
const uint32_t kf06_21[] PROGMEM = { 
K_K(379700.00), K_K(380172.22), K_K(380644.44), K_K(381116.67), 
K_K(381588.89), K_K(382061.11), K_K(382533.33), K_K(383005.56), 
K_K(383477.78), K_K(383950.00) };
#define KL06_21 ( 120 )

const uint8_t kn06_22[] PROGMEM = "Clostr.acetobut";
const uint32_t kf06_22[] PROGMEM = { 
K_K(382800.00), K_K(383725.56), K_K(384651.11), K_K(385576.67), 
K_K(386502.22), K_K(387427.78), K_K(388353.33), K_K(389278.89), 
K_K(390204.44), K_K(391130.00) };
#define KL06_22 ( 120 )

const uint8_t kn06_23[] PROGMEM = "Clostr.botulinu";
const uint32_t kf06_23[] PROGMEM = { 
K_K(361000.00), K_K(361370.00), K_K(361740.00), K_K(362110.00), 
K_K(362480.00), K_K(362850.00), K_K(363220.00), K_K(363590.00), 
K_K(363960.00), K_K(364330.00) };
#define KL06_23 ( 120 )

const uint8_t kn06_24[] PROGMEM = "Clostr.perfring";
const uint32_t kf06_24[] PROGMEM = { 
K_K(394200.00), K_K(394633.33), K_K(395066.67), K_K(395500.00), 
K_K(395933.33), K_K(396366.67), K_K(396800.00), K_K(397233.33), 
K_K(397666.67), K_K(398100.00) };
#define KL06_24 ( 120 )

const uint8_t kn06_25[] PROGMEM = "Clostr.septicum";
const uint32_t kf06_25[] PROGMEM = { 
K_K(362050.00), K_K(362444.44), K_K(362838.89), K_K(363233.33), 
K_K(363627.78), K_K(364022.22), K_K(364416.67), K_K(364811.11), 
K_K(365205.56), K_K(365600.00) };
#define KL06_25 ( 120 )

const uint8_t kn06_26[] PROGMEM = "Coryneb.diphthe";
const uint32_t kf06_26[] PROGMEM = { 
K_K(340000.00), K_K(340444.44), K_K(340888.89), K_K(341333.33), 
K_K(341777.78), K_K(342222.22), K_K(342666.67), K_K(343111.11), 
K_K(343555.56), K_K(344000.00) };
#define KL06_26 ( 120 )

const uint8_t kn06_27[] PROGMEM = "Coryneb.xerosis";
const uint32_t kf06_27[] PROGMEM = { 
K_K(315650.00), K_K(315777.78), K_K(315905.56), K_K(316033.33), 
K_K(316161.11), K_K(316288.89), K_K(316416.67), K_K(316544.44), 
K_K(316672.22), K_K(316800.00) };
#define KL06_27 ( 120 )

const uint8_t kn06_28[] PROGMEM = "Cytophaga rubra";
const uint32_t kf06_28[] PROGMEM = { 
K_K(428100.00), K_K(428555.56), K_K(429011.11), K_K(429466.67), 
K_K(429922.22), K_K(430377.78), K_K(430833.33), K_K(431288.89), 
K_K(431744.44), K_K(432200.00) };
#define KL06_28 ( 120 )

const uint8_t kn06_29[] PROGMEM = "Diploc.diphther";
const uint32_t kf06_29[] PROGMEM = { 
K_K(357950.00), K_K(358622.22), K_K(359294.44), K_K(359966.67), 
K_K(360638.89), K_K(361311.11), K_K(361983.33), K_K(362655.56), 
K_K(363327.78), K_K(364000.00) };
#define KL06_29 ( 120 )

const uint8_t kn06_30[] PROGMEM = "Diploc.pneumoni";
const uint32_t kf06_30[] PROGMEM = { 
K_K(351650.00), K_K(353516.67), K_K(355383.33), K_K(357250.00), 
K_K(359116.67), K_K(360983.33), K_K(362850.00), K_K(364716.67), 
K_K(366583.33), K_K(368450.00) };
#define KL06_30 ( 120 )

const uint8_t kn06_31[] PROGMEM = "Enterob.aerogen";
const uint32_t kf06_31[] PROGMEM = { K_K(374000.00) };
#define KL06_31 ( 1200 )

const uint8_t kn06_32[] PROGMEM = "Erwinia amylov.03472";
const uint32_t kf06_32[] PROGMEM = { 
K_K(352100.00), K_K(312977.78), K_K(273855.55), K_K(234733.33), 
K_K(195611.11), K_K(156488.89), K_K(117366.66), K_K(78244.44), 
K_K(39122.22), K_K(0.00) };
#define KL06_32 ( 120 )

const uint8_t kn06_33[] PROGMEM = "Erwinia carotov";
const uint32_t kf06_33[] PROGMEM = { 
K_K(368100.00), K_K(369088.89), K_K(370077.78), K_K(371066.67), 
K_K(372055.56), K_K(373044.44), K_K(374033.33), K_K(375022.22), 
K_K(376011.11), K_K(377000.00) };
#define KL06_33 ( 120 )

const uint8_t kn06_34[] PROGMEM = "Escher.coli.E1";
const uint32_t kf06_34[] PROGMEM = { K_K(356000.00) };
#define KL06_34 ( 1200 )

const uint8_t kn06_35[] PROGMEM = "Escher.coli.E2";
const uint32_t kf06_35[] PROGMEM = { 
K_K(392000.00), K_K(392111.11), K_K(392222.22), K_K(392333.33), 
K_K(392444.44), K_K(392555.56), K_K(392666.67), K_K(392777.78), 
K_K(392888.89), K_K(393000.00) };
#define KL06_35 ( 120 )

const uint8_t kn06_36[] PROGMEM = "Gaffkya tetrage";
const uint32_t kf06_36[] PROGMEM = { 
K_K(344850.00), K_K(345700.00), K_K(346550.00), K_K(347400.00), 
K_K(348250.00), K_K(349100.00), K_K(349950.00), K_K(350800.00), 
K_K(351650.00), K_K(352500.00) };
#define KL06_36 ( 120 )

const uint8_t kn06_37[] PROGMEM = "Gardnerella vag";
const uint32_t kf06_37[] PROGMEM = { 
K_K(338000.00), K_K(338505.56), K_K(339011.11), K_K(339516.67), 
K_K(340022.22), K_K(340527.78), K_K(341033.33), K_K(341538.89), 
K_K(342044.44), K_K(342550.00) };
#define KL06_37 ( 120 )

const uint8_t kn06_38[] PROGMEM = "Haemophilus inf";
const uint32_t kf06_38[] PROGMEM = { K_K(336410.00) };
#define KL06_38 ( 1200 )

const uint8_t kn06_39[] PROGMEM = "Klebsiella pneu";
const uint32_t kf06_39[] PROGMEM = { 
K_K(398450.00), K_K(399138.89), K_K(399827.78), K_K(400516.67), 
K_K(401205.56), K_K(401894.44), K_K(402583.33), K_K(403272.22), 
K_K(403961.11), K_K(404650.00) };
#define KL06_39 ( 120 )

const uint8_t kn06_40[] PROGMEM = "Klebsiella pne2";
const uint32_t kf06_40[] PROGMEM = { 
K_K(416900.00), K_K(417455.56), K_K(418011.11), K_K(418566.67), 
K_K(419122.22), K_K(419677.78), K_K(420233.33), K_K(420788.89), 
K_K(421344.44), K_K(421900.00) };
#define KL06_40 ( 120 )

const uint8_t kn06_41[] PROGMEM = "Lactobac.acidop";
const uint32_t kf06_41[] PROGMEM = { 
K_K(346050.00), K_K(346672.22), K_K(347294.44), K_K(347916.67), 
K_K(348538.89), K_K(349161.11), K_K(349783.33), K_K(350405.56), 
K_K(351027.78), K_K(351650.00) };
#define KL06_41 ( 120 )

const uint8_t kn06_42[] PROGMEM = "Leptosp.interro";
const uint32_t kf06_42[] PROGMEM = { 
K_K(397050.00), K_K(397500.00), K_K(397950.00), K_K(398400.00), 
K_K(398850.00), K_K(399300.00), K_K(399750.00), K_K(400200.00), 
K_K(400650.00), K_K(401100.00) };
#define KL06_42 ( 120 )

const uint8_t kn06_43[] PROGMEM = "Mycobact.phlei";
const uint32_t kf06_43[] PROGMEM = { 
K_K(409650.00), K_K(409761.11), K_K(409872.22), K_K(409983.33), 
K_K(410094.44), K_K(410205.56), K_K(410316.67), K_K(410427.78), 
K_K(410538.89), K_K(410650.00) };
#define KL06_43 ( 120 )

const uint8_t kn06_44[] PROGMEM = "Mycobact.tuberc";
const uint32_t kf06_44[] PROGMEM = { 
K_K(430550.00), K_K(430955.56), K_K(431361.11), K_K(431766.67), 
K_K(432172.22), K_K(432577.78), K_K(432983.33), K_K(433388.89), 
K_K(433794.44), K_K(434200.00) };
#define KL06_44 ( 120 )

const uint8_t kn06_45[] PROGMEM = "Mycoplasma";
const uint32_t kf06_45[] PROGMEM = { 
K_K(322850.00), K_K(322966.67), K_K(323083.33), K_K(323200.00), 
K_K(323316.67), K_K(323433.33), K_K(323550.00), K_K(323666.67), 
K_K(323783.33), K_K(323900.00) };
#define KL06_45 ( 120 )

const uint8_t kn06_46[] PROGMEM = "Mycoplasma 2nd";
const uint32_t kf06_46[] PROGMEM = { 
K_K(342750.00), K_K(343477.78), K_K(344205.56), K_K(344933.33), 
K_K(345661.11), K_K(346388.89), K_K(347116.67), K_K(347844.44), 
K_K(348572.22), K_K(349300.00) };
#define KL06_46 ( 120 )

const uint8_t kn06_47[] PROGMEM = "Neiss.gonorrhea";
const uint32_t kf06_47[] PROGMEM = { 
K_K(333850.00), K_K(334144.44), K_K(334438.89), K_K(334733.33), 
K_K(335027.78), K_K(335322.22), K_K(335616.67), K_K(335911.11), 
K_K(336205.56), K_K(336500.00) };
#define KL06_47 ( 120 )

const uint8_t kn06_48[] PROGMEM = "Nocard.asteroi2";
const uint32_t kf06_48[] PROGMEM = { 
K_K(363700.00), K_K(364400.00), K_K(365100.00), K_K(365800.00), 
K_K(366500.00), K_K(367200.00), K_K(367900.00), K_K(368600.00), 
K_K(369300.00), K_K(370000.00) };
#define KL06_48 ( 120 )

const uint8_t kn06_49[] PROGMEM = "Nocard.asteroid";
const uint32_t kf06_49[] PROGMEM = { 
K_K(354950.00), K_K(354994.44), K_K(355038.89), K_K(355083.33), 
K_K(355127.78), K_K(355172.22), K_K(355216.67), K_K(355261.11), 
K_K(355305.56), K_K(355350.00) };
#define KL06_49 ( 120 )

const uint8_t kn06_50[] PROGMEM = "Propionob.acnes";
const uint32_t kf06_50[] PROGMEM = { 
K_K(383750.00), K_K(384333.33), K_K(384916.67), K_K(385500.00), 
K_K(386083.33), K_K(386666.67), K_K(387250.00), K_K(387833.33), 
K_K(388416.67), K_K(389000.00) };
#define KL06_50 ( 120 )

const uint8_t kn06_51[] PROGMEM = "Proteus mirabil";
const uint32_t kf06_51[] PROGMEM = { 
K_K(320550.00), K_K(321155.56), K_K(321761.11), K_K(322366.67), 
K_K(322972.22), K_K(323577.78), K_K(324183.33), K_K(324788.89), 
K_K(325394.44), K_K(326000.00) };
#define KL06_51 ( 120 )

const uint8_t kn06_52[] PROGMEM = "Proteus mirabi2";
const uint32_t kf06_52[] PROGMEM = { 
K_K(345950.00), K_K(346633.33), K_K(347316.67), K_K(348000.00), 
K_K(348683.33), K_K(349366.67), K_K(350050.00), K_K(350733.33), 
K_K(351416.67), K_K(352100.00) };
#define KL06_52 ( 120 )

const uint8_t kn06_53[] PROGMEM = "Proteus vulgar.";
const uint32_t kf06_53[] PROGMEM = { 
K_K(408750.00), K_K(409605.56), K_K(410461.11), K_K(411316.67), 
K_K(412172.22), K_K(413027.78), K_K(413883.33), K_K(414738.89), 
K_K(415594.44), K_K(416450.00) };
#define KL06_53 ( 120 )

const uint8_t kn06_54[] PROGMEM = "Proteus vulgar2";
const uint32_t kf06_54[] PROGMEM = { 
K_K(333750.00), K_K(334350.00), K_K(334950.00), K_K(335550.00), 
K_K(336150.00), K_K(336750.00), K_K(337350.00), K_K(337950.00), 
K_K(338550.00), K_K(339150.00) };
#define KL06_54 ( 120 )

const uint8_t kn06_55[] PROGMEM = "Proteus vulgar3";
const uint32_t kf06_55[] PROGMEM = { 
K_K(327200.00), K_K(327455.56), K_K(327711.11), K_K(327966.67), 
K_K(328222.22), K_K(328477.78), K_K(328733.33), K_K(328988.89), 
K_K(329244.44), K_K(329500.00) };
#define KL06_55 ( 120 )

const uint8_t kn06_56[] PROGMEM = "Pseudom.aerugin";
const uint32_t kf06_56[] PROGMEM = { 
K_K(331250.00), K_K(331622.22), K_K(331994.44), K_K(332366.67), 
K_K(332738.89), K_K(333111.11), K_K(333483.33), K_K(333855.56), 
K_K(334227.78), K_K(334600.00) };
#define KL06_56 ( 120 )

const uint8_t kn06_57[] PROGMEM = "Salmon.enteridi";
const uint32_t kf06_57[] PROGMEM = { K_K(329000.00) };
#define KL06_57 ( 1200 )

const uint8_t kn06_58[] PROGMEM = "Salmon.paratyph";
const uint32_t kf06_58[] PROGMEM = { 
K_K(365050.00), K_K(365611.11), K_K(366172.22), K_K(366733.33), 
K_K(367294.44), K_K(367855.56), K_K(368416.67), K_K(368977.78), 
K_K(369538.89), K_K(370100.00) };
#define KL06_58 ( 120 )

const uint8_t kn06_59[] PROGMEM = "Salmon.typhimur";
const uint32_t kf06_59[] PROGMEM = { 
K_K(382300.00), K_K(382772.22), K_K(383244.44), K_K(383716.67), 
K_K(384188.89), K_K(384661.11), K_K(385133.33), K_K(385605.56), 
K_K(386077.78), K_K(386550.00) };
#define KL06_59 ( 120 )

const uint8_t kn06_60[] PROGMEM = "Serrat.marcesc.";
const uint32_t kf06_60[] PROGMEM = { 
K_K(349450.00), K_K(349744.44), K_K(350038.89), K_K(350333.33), 
K_K(350627.78), K_K(350922.22), K_K(351216.67), K_K(351511.11), 
K_K(351805.56), K_K(352100.00) };
#define KL06_60 ( 120 )

const uint8_t kn06_61[] PROGMEM = "Shigel.dysenter";
const uint32_t kf06_61[] PROGMEM = { 
K_K(390090.00), K_K(390080.00), K_K(390070.00), K_K(390060.00), 
K_K(390050.00), K_K(390040.00), K_K(390030.00), K_K(390020.00), 
K_K(390010.00), K_K(390000.00) };
#define KL06_61 ( 120 )

const uint8_t kn06_62[] PROGMEM = "Shigel.flexneri";
const uint32_t kf06_62[] PROGMEM = { K_K(394000.00) };
#define KL06_62 ( 1200 )

const uint8_t kn06_63[] PROGMEM = "Shigella sonnei";
const uint32_t kf06_63[] PROGMEM = { K_K(318000.00) };
#define KL06_63 ( 1200 )

const uint8_t kn06_64[] PROGMEM = "Sphaerot.natans";
const uint32_t kf06_64[] PROGMEM = { 
K_K(388400.00), K_K(388961.11), K_K(389522.22), K_K(390083.33), 
K_K(390644.44), K_K(391205.56), K_K(391766.67), K_K(392327.78), 
K_K(392888.89), K_K(393450.00) };
#define KL06_64 ( 120 )

const uint8_t kn06_65[] PROGMEM = "Spirill.serpens";
const uint32_t kf06_65[] PROGMEM = { 
K_K(378350.00), K_K(378844.44), K_K(379338.89), K_K(379833.33), 
K_K(380327.78), K_K(380822.22), K_K(381316.67), K_K(381811.11), 
K_K(382305.56), K_K(382800.00) };
#define KL06_65 ( 120 )

const uint8_t kn06_66[] PROGMEM = "Staphylo.aureus";
const uint32_t kf06_66[] PROGMEM = { 
K_K(376270.00), K_K(376778.89), K_K(377287.78), K_K(377796.67), 
K_K(378305.56), K_K(378814.44), K_K(379323.33), K_K(379832.22), 
K_K(380341.11), K_K(380850.00) };
#define KL06_66 ( 120 )

const uint8_t kn06_67[] PROGMEM = "Staphyl.aureus2";
const uint32_t kf06_67[] PROGMEM = { K_K(381000.00) };
#define KL06_67 ( 1200 )

const uint8_t kn06_68[] PROGMEM = "Streptoc.lactis";
const uint32_t kf06_68[] PROGMEM = { 
K_K(382000.00), K_K(382555.56), K_K(383111.11), K_K(383666.67), 
K_K(384222.22), K_K(384777.78), K_K(385333.33), K_K(385888.89), 
K_K(386444.44), K_K(387000.00) };
#define KL06_68 ( 120 )

const uint8_t kn06_69[] PROGMEM = "Streptoc.mitis";
const uint32_t kf06_69[] PROGMEM = { 
K_K(313800.00), K_K(314611.11), K_K(315422.22), K_K(316233.33), 
K_K(317044.44), K_K(317855.56), K_K(318666.67), K_K(319477.78), 
K_K(320288.89), K_K(321100.00) };
#define KL06_69 ( 120 )

const uint8_t kn06_70[] PROGMEM = "Strept.pneumoni";
const uint32_t kf06_70[] PROGMEM = { 
K_K(366850.00), K_K(367222.22), K_K(367594.44), K_K(367966.67), 
K_K(368338.89), K_K(368711.11), K_K(369083.33), K_K(369455.56), 
K_K(369827.78), K_K(370200.00) };
#define KL06_70 ( 120 )

const uint8_t kn06_71[] PROGMEM = "Strept.pyogenes";
const uint32_t kf06_71[] PROGMEM = { 
K_K(360500.00), K_K(362144.44), K_K(363788.89), K_K(365433.33), 
K_K(367077.78), K_K(368722.22), K_K(370366.67), K_K(372011.11), 
K_K(373655.56), K_K(375300.00) };
#define KL06_71 ( 120 )

const uint8_t kn06_72[] PROGMEM = "Streptococ.sp.G";
const uint32_t kf06_72[] PROGMEM = { 
K_K(368150.00), K_K(368227.78), K_K(368305.56), K_K(368383.33), 
K_K(368461.11), K_K(368538.89), K_K(368616.67), K_K(368694.44), 
K_K(368772.22), K_K(368850.00) };
#define KL06_72 ( 120 )

const uint8_t kn06_73[] PROGMEM = "Sub.spores bac.";
const uint32_t kf06_73[] PROGMEM = { 
K_K(385150.00), K_K(385238.89), K_K(385327.78), K_K(385416.67), 
K_K(385505.56), K_K(385594.44), K_K(385683.33), K_K(385772.22), 
K_K(385861.11), K_K(385950.00) };
#define KL06_73 ( 120 )

const uint8_t kn06_74[] PROGMEM = "Trepon.pallidum";
const uint32_t kf06_74[] PROGMEM = { 
K_K(346850.00), K_K(346911.11), K_K(346972.22), K_K(347033.33), 
K_K(347094.44), K_K(347155.56), K_K(347216.67), K_K(347277.78), 
K_K(347338.89), K_K(347400.00) };
#define KL06_74 ( 120 )

const uint8_t kn06_75[] PROGMEM = "Veillone.dispar";
const uint32_t kf06_75[] PROGMEM = { 
K_K(401750.00), K_K(402133.33), K_K(402516.67), K_K(402900.00), 
K_K(403283.33), K_K(403666.67), K_K(404050.00), K_K(404433.33), 
K_K(404816.67), K_K(405200.00) };
#define KL06_75 ( 120 )

const uint8_t * const kpg_n06[] PROGMEM = { 
kn06_01, kn06_02, kn06_03, kn06_04, kn06_05, kn06_06, kn06_07, kn06_08, 
kn06_09, kn06_10, kn06_11, kn06_12, kn06_13, kn06_14, kn06_15, kn06_16, kn06_17, 
kn06_18, kn06_19, kn06_20, kn06_21, kn06_22, kn06_23, kn06_24, kn06_25, kn06_26, 
kn06_27, kn06_28, kn06_29, kn06_30, kn06_31, kn06_32, kn06_33, kn06_34, kn06_35, 
kn06_36, kn06_37, kn06_38, kn06_39, kn06_40, kn06_41, kn06_42, kn06_43, kn06_44, 
kn06_45, kn06_46, kn06_47, kn06_48, kn06_49, kn06_50, kn06_51, kn06_52, kn06_53, 
kn06_54, kn06_55, kn06_56, kn06_57, kn06_58, kn06_59, kn06_60, kn06_61, kn06_62, 
kn06_63, kn06_64, kn06_65, kn06_66, kn06_67, kn06_68, kn06_69, kn06_70, kn06_71, 
kn06_72, kn06_73, kn06_74, kn06_75, (uint8_t *)0 };
const uint32_t * const kpg_f06[] PROGMEM = { 
kf06_01, kf06_02, kf06_03, kf06_04, kf06_05, kf06_06, kf06_07, kf06_08, 
kf06_09, kf06_10, kf06_11, kf06_12, kf06_13, kf06_14, kf06_15, kf06_16, kf06_17, 
kf06_18, kf06_19, kf06_20, kf06_21, kf06_22, kf06_23, kf06_24, kf06_25, kf06_26, 
kf06_27, kf06_28, kf06_29, kf06_30, kf06_31, kf06_32, kf06_33, kf06_34, kf06_35, 
kf06_36, kf06_37, kf06_38, kf06_39, kf06_40, kf06_41, kf06_42, kf06_43, kf06_44, 
kf06_45, kf06_46, kf06_47, kf06_48, kf06_49, kf06_50, kf06_51, kf06_52, kf06_53, 
kf06_54, kf06_55, kf06_56, kf06_57, kf06_58, kf06_59, kf06_60, kf06_61, kf06_62, 
kf06_63, kf06_64, kf06_65, kf06_66, kf06_67, kf06_68, kf06_69, kf06_70, kf06_71, 
kf06_72, kf06_73, kf06_74, kf06_75 };
const uint8_t kpg_j06[] PROGMEM = { 
K_S(kf06_01), K_S(kf06_02), K_S(kf06_03), K_S(kf06_04), K_S(kf06_05), K_S(kf06_06), K_S(kf06_07), K_S(kf06_08), 
K_S(kf06_09), K_S(kf06_10), K_S(kf06_11), K_S(kf06_12), K_S(kf06_13), K_S(kf06_14), K_S(kf06_15), K_S(kf06_16), K_S(kf06_17), 
K_S(kf06_18), K_S(kf06_19), K_S(kf06_20), K_S(kf06_21), K_S(kf06_22), K_S(kf06_23), K_S(kf06_24), K_S(kf06_25), K_S(kf06_26), 
K_S(kf06_27), K_S(kf06_28), K_S(kf06_29), K_S(kf06_30), K_S(kf06_31), K_S(kf06_32), K_S(kf06_33), K_S(kf06_34), K_S(kf06_35), 
K_S(kf06_36), K_S(kf06_37), K_S(kf06_38), K_S(kf06_39), K_S(kf06_40), K_S(kf06_41), K_S(kf06_42), K_S(kf06_43), K_S(kf06_44), 
K_S(kf06_45), K_S(kf06_46), K_S(kf06_47), K_S(kf06_48), K_S(kf06_49), K_S(kf06_50), K_S(kf06_51), K_S(kf06_52), K_S(kf06_53), 
K_S(kf06_54), K_S(kf06_55), K_S(kf06_56), K_S(kf06_57), K_S(kf06_58), K_S(kf06_59), K_S(kf06_60), K_S(kf06_61), K_S(kf06_62), 
K_S(kf06_63), K_S(kf06_64), K_S(kf06_65), K_S(kf06_66), K_S(kf06_67), K_S(kf06_68), K_S(kf06_69), K_S(kf06_70), K_S(kf06_71), 
K_S(kf06_72), K_S(kf06_73), K_S(kf06_74), K_S(kf06_75) };
const uint16_t kpg_t06[] PROGMEM = { 
KL06_01, KL06_02, KL06_03, KL06_04, KL06_05, KL06_06, KL06_07, KL06_08, 
KL06_09, KL06_10, KL06_11, KL06_12, KL06_13, KL06_14, KL06_15, KL06_16, KL06_17, 
KL06_18, KL06_19, KL06_20, KL06_21, KL06_22, KL06_23, KL06_24, KL06_25, KL06_26, 
KL06_27, KL06_28, KL06_29, KL06_30, KL06_31, KL06_32, KL06_33, KL06_34, KL06_35, 
KL06_36, KL06_37, KL06_38, KL06_39, KL06_40, KL06_41, KL06_42, KL06_43, KL06_44, 
KL06_45, KL06_46, KL06_47, KL06_48, KL06_49, KL06_50, KL06_51, KL06_52, KL06_53, 
KL06_54, KL06_55, KL06_56, KL06_57, KL06_58, KL06_59, KL06_60, KL06_61, KL06_62, 
KL06_63, KL06_64, KL06_65, KL06_66, KL06_67, KL06_68, KL06_69, KL06_70, KL06_71, 
KL06_72, KL06_73, KL06_74, KL06_75 };

//******************************************
const uint8_t kpg_07[] PROGMEM = "œ–Œ—“≈…ÿ»≈";

const uint8_t kn07_01[] PROGMEM = "Balant.coli cys";
const uint32_t kf07_01[] PROGMEM = { 
K_K(458800.00), K_K(459255.56), K_K(459711.11), K_K(460166.67), 
K_K(460622.22), K_K(461077.78), K_K(461533.33), K_K(461988.89), 
K_K(462444.44), K_K(462900.00) };
#define KL07_01 ( 120 )

const uint8_t kn07_02[] PROGMEM = "Chilomast.cysts";
const uint32_t kf07_02[] PROGMEM = { 
K_K(425200.00), K_K(425433.33), K_K(425666.67), K_K(425900.00), 
K_K(426133.33), K_K(426366.67), K_K(426600.00), K_K(426833.33), 
K_K(427066.67), K_K(427300.00) };
#define KL07_02 ( 120 )

const uint8_t kn07_03[] PROGMEM = "Chilomas.cysts2";
const uint32_t kf07_03[] PROGMEM = { 
K_K(388950.00), K_K(389144.44), K_K(389338.89), K_K(389533.33), 
K_K(389727.78), K_K(389922.22), K_K(390116.67), K_K(390311.11), 
K_K(390505.56), K_K(390700.00) };
#define KL07_03 ( 120 )

const uint8_t kn07_04[] PROGMEM = "Chilomonas";
const uint32_t kf07_04[] PROGMEM = { 
K_K(393750.00), K_K(394444.44), K_K(395138.89), K_K(395833.33), 
K_K(396527.78), K_K(397222.22), K_K(397916.67), K_K(398611.11), 
K_K(399305.56), K_K(400000.00) };
#define KL07_04 ( 120 )

const uint8_t kn07_05[] PROGMEM = "Dientamoeb.frag";
const uint32_t kf07_05[] PROGMEM = { 
K_K(401350.00), K_K(401872.22), K_K(402394.44), K_K(402916.67), 
K_K(403438.89), K_K(403961.11), K_K(404483.33), K_K(405005.56), 
K_K(405527.78), K_K(406050.00) };
#define KL07_05 ( 120 )

const uint8_t kn07_06[] PROGMEM = "Endamoeb.gingiv";
const uint32_t kf07_06[] PROGMEM = { 
K_K(433800.00), K_K(434600.00), K_K(435400.00), K_K(436200.00), 
K_K(437000.00), K_K(437800.00), K_K(438600.00), K_K(439400.00), 
K_K(440200.00), K_K(441000.00) };
#define KL07_06 ( 120 )

const uint8_t kn07_07[] PROGMEM = "Endol.nana trop";
const uint32_t kf07_07[] PROGMEM = { 
K_K(394250.00), K_K(394566.67), K_K(394883.33), K_K(395200.00), 
K_K(395516.67), K_K(395833.33), K_K(396150.00), K_K(396466.67), 
K_K(396783.33), K_K(397100.00) };
#define KL07_07 ( 120 )

const uint8_t kn07_08[] PROGMEM = "Endolimax.nana2";
const uint32_t kf07_08[] PROGMEM = { 
K_K(430500.00), K_K(430816.67), K_K(431133.33), K_K(431450.00), 
K_K(431766.67), K_K(432083.33), K_K(432400.00), K_K(432716.67), 
K_K(433033.33), K_K(433350.00) };
#define KL07_08 ( 120 )

const uint8_t kn07_09[] PROGMEM = "Entamoeb.c.trop";
const uint32_t kf07_09[] PROGMEM = { 
K_K(397000.00), K_K(397372.22), K_K(397744.44), K_K(398116.67), 
K_K(398488.89), K_K(398861.11), K_K(399233.33), K_K(399605.56), 
K_K(399977.78), K_K(400350.00) };
#define KL07_09 ( 120 )

const uint8_t kn07_10[] PROGMEM = "Entam.histol.tr";
const uint32_t kf07_10[] PROGMEM = { 
K_K(381100.00), K_K(381844.44), K_K(382588.89), K_K(383333.33), 
K_K(384077.78), K_K(384822.22), K_K(385566.67), K_K(386311.11), 
K_K(387055.56), K_K(387800.00) };
#define KL07_10 ( 120 )

const uint8_t kn07_11[] PROGMEM = "Giardia lamblia";
const uint32_t kf07_11[] PROGMEM = { 
K_K(421400.00), K_K(421944.44), K_K(422488.89), K_K(423033.33), 
K_K(423577.78), K_K(424122.22), K_K(424666.67), K_K(425211.11), 
K_K(425755.56), K_K(426300.00) };
#define KL07_11 ( 120 )

const uint8_t kn07_12[] PROGMEM = "Histomon.meleag";
const uint32_t kf07_12[] PROGMEM = { 
K_K(376550.00), K_K(376788.89), K_K(377027.78), K_K(377266.67), 
K_K(377505.56), K_K(377744.44), K_K(377983.33), K_K(378222.22), 
K_K(378461.11), K_K(378700.00) };
#define KL07_12 ( 120 )

const uint8_t kn07_13[] PROGMEM = "Iodamoeba buts2";
const uint32_t kf07_13[] PROGMEM = { 
K_K(398150.00), K_K(398883.33), K_K(399616.67), K_K(400350.00), 
K_K(401083.33), K_K(401816.67), K_K(402550.00), K_K(403283.33), 
K_K(404016.67), K_K(404750.00) };
#define KL07_13 ( 120 )

const uint8_t kn07_14[] PROGMEM = "Iodamoeba butsc";
const uint32_t kf07_14[] PROGMEM = { 
K_K(437850.00), K_K(439033.33), K_K(440216.67), K_K(441400.00), 
K_K(442583.33), K_K(443766.67), K_K(444950.00), K_K(446133.33), 
K_K(447316.67), K_K(448500.00) };
#define KL07_14 ( 120 )

const uint8_t kn07_15[] PROGMEM = "Leishmania braz";
const uint32_t kf07_15[] PROGMEM = { 
K_K(400050.00), K_K(400611.11), K_K(401172.22), K_K(401733.33), 
K_K(402294.44), K_K(402855.56), K_K(403416.67), K_K(403977.78), 
K_K(404538.89), K_K(405100.00) };
#define KL07_15 ( 120 )

const uint8_t kn07_16[] PROGMEM = "Leishman.donova";
const uint32_t kf07_16[] PROGMEM = { 
K_K(398000.00), K_K(398516.67), K_K(399033.33), K_K(399550.00), 
K_K(400066.67), K_K(400583.33), K_K(401100.00), K_K(401616.67), 
K_K(402133.33), K_K(402650.00) };
#define KL07_16 ( 120 )

const uint8_t kn07_17[] PROGMEM = "Leishman.mexica";
const uint32_t kf07_17[] PROGMEM = { 
K_K(400200.00), K_K(400600.00), K_K(401000.00), K_K(401400.00), 
K_K(401800.00), K_K(402200.00), K_K(402600.00), K_K(403000.00), 
K_K(403400.00), K_K(403800.00) };
#define KL07_17 ( 120 )

const uint8_t kn07_18[] PROGMEM = "Leishman.tropic";
const uint32_t kf07_18[] PROGMEM = { 
K_K(402100.00), K_K(402688.89), K_K(403277.78), K_K(403866.67), 
K_K(404455.56), K_K(405044.44), K_K(405633.33), K_K(406222.22), 
K_K(406811.11), K_K(407400.00) };
#define KL07_18 ( 120 )

const uint8_t kn07_19[] PROGMEM = "Leucocytozoon";
const uint32_t kf07_19[] PROGMEM = { 
K_K(397450.00), K_K(398016.67), K_K(398583.33), K_K(399150.00), 
K_K(399716.67), K_K(400283.33), K_K(400850.00), K_K(401416.67), 
K_K(401983.33), K_K(402550.00) };
#define KL07_19 ( 120 )

const uint8_t kn07_20[] PROGMEM = "Naegler.fowleri";
const uint32_t kf07_20[] PROGMEM = { 
K_K(356900.00), K_K(357727.78), K_K(358555.56), K_K(359383.33), 
K_K(360211.11), K_K(361038.89), K_K(361866.67), K_K(362694.44), 
K_K(363522.22), K_K(364350.00) };
#define KL07_20 ( 120 )

const uint8_t kn07_21[] PROGMEM = "Plasmod.cynomol";
const uint32_t kf07_21[] PROGMEM = { 
K_K(417300.00), K_K(418100.00), K_K(418900.00), K_K(419700.00), 
K_K(420500.00), K_K(421300.00), K_K(422100.00), K_K(422900.00), 
K_K(423700.00), K_K(424500.00) };
#define KL07_21 ( 120 )

const uint8_t kn07_22[] PROGMEM = "Plasm.falcip.s";
const uint32_t kf07_22[] PROGMEM = { 
K_K(372300.00), K_K(372466.67), K_K(372633.33), K_K(372800.00), 
K_K(372966.67), K_K(373133.33), K_K(373300.00), K_K(373466.67), 
K_K(373633.33), K_K(373800.00) };
#define KL07_22 ( 120 )

const uint8_t kn07_23[] PROGMEM = "Plasm.vivax sme";
const uint32_t kf07_23[] PROGMEM = { 
K_K(438150.00), K_K(438922.22), K_K(439694.44), K_K(440466.67), 
K_K(441238.89), K_K(442011.11), K_K(442783.33), K_K(443555.56), 
K_K(444327.78), K_K(445100.00) };
#define KL07_23 ( 120 )

const uint8_t kn07_24[] PROGMEM = "Sarcocystis";
const uint32_t kf07_24[] PROGMEM = { 
K_K(450550.00), K_K(451038.89), K_K(451527.78), K_K(452016.67), 
K_K(452505.56), K_K(452994.44), K_K(453483.33), K_K(453972.22), 
K_K(454461.11), K_K(454950.00) };
#define KL07_24 ( 120 )

const uint8_t kn07_25[] PROGMEM = "Toxoplasma h.st";
const uint32_t kf07_25[] PROGMEM = { K_K(395000.00) };
#define KL07_25 ( 1200 )

const uint8_t kn07_26[] PROGMEM = "Tricho.vaginali";
const uint32_t kf07_26[] PROGMEM = { 
K_K(378000.00), K_K(378622.22), K_K(379244.44), K_K(379866.67), 
K_K(380488.89), K_K(381111.11), K_K(381733.33), K_K(382355.56), 
K_K(382977.78), K_K(383600.00) };
#define KL07_26 ( 120 )

const uint8_t kn07_27[] PROGMEM = "Trypanos.brucei";
const uint32_t kf07_27[] PROGMEM = { 
K_K(423200.00), K_K(424111.11), K_K(425022.22), K_K(425933.33), 
K_K(426844.44), K_K(427755.56), K_K(428666.67), K_K(429577.78), 
K_K(430488.89), K_K(431400.00) };
#define KL07_27 ( 120 )

const uint8_t kn07_28[] PROGMEM = "Trypanos.cruzi";
const uint32_t kf07_28[] PROGMEM = { 
K_K(460200.00), K_K(460805.56), K_K(461411.11), K_K(462016.67), 
K_K(462622.22), K_K(463227.78), K_K(463833.33), K_K(464438.89), 
K_K(465044.44), K_K(465650.00) };
#define KL07_28 ( 120 )

const uint8_t kn07_29[] PROGMEM = "Trypan.equiperd";
const uint32_t kf07_29[] PROGMEM = { 
K_K(434600.00), K_K(436450.00), K_K(438300.00), K_K(440150.00), 
K_K(442000.00), K_K(443850.00), K_K(445700.00), K_K(447550.00), 
K_K(449400.00), K_K(451250.00) };
#define KL07_29 ( 120 )

const uint8_t kn07_30[] PROGMEM = "Trypan.gambiens";
const uint32_t kf07_30[] PROGMEM = { 
K_K(393750.00), K_K(394300.00), K_K(394850.00), K_K(395400.00), 
K_K(395950.00), K_K(396500.00), K_K(397050.00), K_K(397600.00), 
K_K(398150.00), K_K(398700.00) };
#define KL07_30 ( 120 )

const uint8_t kn07_31[] PROGMEM = "Trypanos.lewisi";
const uint32_t kf07_31[] PROGMEM = { 
K_K(424500.00), K_K(424666.67), K_K(424833.33), K_K(425000.00), 
K_K(425166.67), K_K(425333.33), K_K(425500.00), K_K(425666.67), 
K_K(425833.33), K_K(426000.00) };
#define KL07_31 ( 120 )

const uint8_t kn07_32[] PROGMEM = "Trypan.rhodesie";
const uint32_t kf07_32[] PROGMEM = { 
K_K(423500.00), K_K(424061.11), K_K(424622.22), K_K(425183.33), 
K_K(425744.44), K_K(426305.56), K_K(426866.67), K_K(427427.78), 
K_K(427988.89), K_K(428550.00) };
#define KL07_32 ( 120 )

const uint8_t * const kpg_n07[] PROGMEM = { 
kn07_01, kn07_02, kn07_03, kn07_04, kn07_05, kn07_06, kn07_07, kn07_08, 
kn07_09, kn07_10, kn07_11, kn07_12, kn07_13, kn07_14, kn07_15, kn07_16, kn07_17, 
kn07_18, kn07_19, kn07_20, kn07_21, kn07_22, kn07_23, kn07_24, kn07_25, kn07_26, 
kn07_27, kn07_28, kn07_29, kn07_30, kn07_31, kn07_32, (uint8_t *)0 };
const uint32_t * const kpg_f07[] PROGMEM = { 
kf07_01, kf07_02, kf07_03, kf07_04, kf07_05, kf07_06, kf07_07, kf07_08, 
kf07_09, kf07_10, kf07_11, kf07_12, kf07_13, kf07_14, kf07_15, kf07_16, kf07_17, 
kf07_18, kf07_19, kf07_20, kf07_21, kf07_22, kf07_23, kf07_24, kf07_25, kf07_26, 
kf07_27, kf07_28, kf07_29, kf07_30, kf07_31, kf07_32 };
const uint8_t kpg_j07[] PROGMEM = { 
K_S(kf07_01), K_S(kf07_02), K_S(kf07_03), K_S(kf07_04), K_S(kf07_05), K_S(kf07_06), K_S(kf07_07), K_S(kf07_08), 
K_S(kf07_09), K_S(kf07_10), K_S(kf07_11), K_S(kf07_12), K_S(kf07_13), K_S(kf07_14), K_S(kf07_15), K_S(kf07_16), K_S(kf07_17), 
K_S(kf07_18), K_S(kf07_19), K_S(kf07_20), K_S(kf07_21), K_S(kf07_22), K_S(kf07_23), K_S(kf07_24), K_S(kf07_25), K_S(kf07_26), 
K_S(kf07_27), K_S(kf07_28), K_S(kf07_29), K_S(kf07_30), K_S(kf07_31), K_S(kf07_32) };
const uint16_t kpg_t07[] PROGMEM = { 
KL07_01, KL07_02, KL07_03, KL07_04, KL07_05, KL07_06, KL07_07, KL07_08, 
KL07_09, KL07_10, KL07_11, KL07_12, KL07_13, KL07_14, KL07_15, KL07_16, KL07_17, 
KL07_18, KL07_19, KL07_20, KL07_21, KL07_22, KL07_23, KL07_24, KL07_25, KL07_26, 
KL07_27, KL07_28, KL07_29, KL07_30, KL07_31, KL07_32 };

//******************************************
const uint8_t kpg_08[] PROGMEM = "Õ≈Ã¿“Œ“€";

const uint8_t kn08_01[] PROGMEM = "Ancylostom.braz";
const uint32_t kf08_01[] PROGMEM = { 
K_K(397600.00), K_K(398227.78), K_K(398855.56), K_K(399483.33), 
K_K(400111.11), K_K(400738.89), K_K(401366.67), K_K(401994.44), 
K_K(402622.22), K_K(403250.00) };
#define KL08_01 ( 120 )

const uint8_t kn08_02[] PROGMEM = "Ancylost.caninu";
const uint32_t kf08_02[] PROGMEM = { 
K_K(383100.00), K_K(385300.00), K_K(387500.00), K_K(389700.00), 
K_K(391900.00), K_K(394100.00), K_K(396300.00), K_K(398500.00), 
K_K(400700.00), K_K(402900.00) };
#define KL08_02 ( 120 )

const uint8_t kn08_03[] PROGMEM = "Ascaris lar.lun";
const uint32_t kf08_03[] PROGMEM = { 
K_K(404900.00), K_K(405372.22), K_K(405844.44), K_K(406316.67), 
K_K(406788.89), K_K(407261.11), K_K(407733.33), K_K(408205.56), 
K_K(408677.78), K_K(409150.00) };
#define KL08_03 ( 120 )

const uint8_t kn08_04[] PROGMEM = "Ascaris megaloc";
const uint32_t kf08_04[] PROGMEM = { 
K_K(403850.00), K_K(404500.00), K_K(405150.00), K_K(405800.00), 
K_K(406450.00), K_K(407100.00), K_K(407750.00), K_K(408400.00), 
K_K(409050.00), K_K(409700.00) };
#define KL08_04 ( 120 )

const uint8_t kn08_05[] PROGMEM = "Capillari.hepat";
const uint32_t kf08_05[] PROGMEM = { 
K_K(424250.00), K_K(424961.11), K_K(425672.22), K_K(426383.33), 
K_K(427094.44), K_K(427805.56), K_K(428516.67), K_K(429227.78), 
K_K(429938.89), K_K(430650.00) };
#define KL08_05 ( 120 )

const uint8_t kn08_06[] PROGMEM = "Dirofilar.immit";
const uint32_t kf08_06[] PROGMEM = { 
K_K(408150.00), K_K(408483.33), K_K(408816.67), K_K(409150.00), 
K_K(409483.33), K_K(409816.67), K_K(410150.00), K_K(410483.33), 
K_K(410816.67), K_K(411150.00) };
#define KL08_06 ( 120 )

const uint8_t kn08_07[] PROGMEM = "Enterob.vermicu";
const uint32_t kf08_07[] PROGMEM = { 
K_K(420950.00), K_K(421544.44), K_K(422138.89), K_K(422733.33), 
K_K(423327.78), K_K(423922.22), K_K(424516.67), K_K(425111.11), 
K_K(425705.56), K_K(426300.00) };
#define KL08_07 ( 120 )

const uint8_t kn08_08[] PROGMEM = "Haemonch.contor";
const uint32_t kf08_08[] PROGMEM = { 
K_K(386800.00), K_K(387766.67), K_K(388733.33), K_K(389700.00), 
K_K(390666.67), K_K(391633.33), K_K(392600.00), K_K(393566.67), 
K_K(394533.33), K_K(395500.00) };
#define KL08_08 ( 120 )

const uint8_t kn08_09[] PROGMEM = "Loa loa";
const uint32_t kf08_09[] PROGMEM = { K_K(360550.00) };
#define KL08_09 ( 1200 )

const uint8_t kn08_10[] PROGMEM = "Onchocerca volv";
const uint32_t kf08_10[] PROGMEM = { 
K_K(436300.00), K_K(436944.44), K_K(437588.89), K_K(438233.33), 
K_K(438877.78), K_K(439522.22), K_K(440166.67), K_K(440811.11), 
K_K(441455.56), K_K(442100.00) };
#define KL08_10 ( 120 )

const uint8_t kn08_11[] PROGMEM = "Passalur.ambigu";
const uint32_t kf08_11[] PROGMEM = { 
K_K(428800.00), K_K(430505.56), K_K(432211.11), K_K(433916.67), 
K_K(435622.22), K_K(437327.78), K_K(439033.33), K_K(440738.89), 
K_K(442444.44), K_K(444150.00) };
#define KL08_11 ( 120 )

const uint8_t kn08_12[] PROGMEM = "Stephanur.denta";
const uint32_t kf08_12[] PROGMEM = { 
K_K(457350.00), K_K(457988.89), K_K(458627.78), K_K(459266.67), 
K_K(459905.56), K_K(460544.44), K_K(461183.33), K_K(461822.22), 
K_K(462461.11), K_K(463100.00) };
#define KL08_12 ( 120 )

const uint8_t kn08_13[] PROGMEM = "Strongyloides f";
const uint32_t kf08_13[] PROGMEM = { 
K_K(398400.00), K_K(398800.00), K_K(399200.00), K_K(399600.00), 
K_K(400000.00), K_K(400400.00), K_K(400800.00), K_K(401200.00), 
K_K(401600.00), K_K(402000.00) };
#define KL08_13 ( 120 )

const uint8_t kn08_14[] PROGMEM = "Trichinel.spira";
const uint32_t kf08_14[] PROGMEM = { 
K_K(403850.00), K_K(404041.11), K_K(404232.22), K_K(404423.33), 
K_K(404614.44), K_K(404805.56), K_K(404996.67), K_K(405187.78), 
K_K(405378.89), K_K(405570.00) };
#define KL08_14 ( 120 )

const uint8_t kn08_15[] PROGMEM = "Trichur.sp.male";
const uint32_t kf08_15[] PROGMEM = { 
K_K(388300.00), K_K(390588.89), K_K(392877.78), K_K(395166.67), 
K_K(397455.56), K_K(399744.44), K_K(402033.33), K_K(404322.22), 
K_K(406611.11), K_K(408900.00) };
#define KL08_15 ( 120 )

const uint8_t * const kpg_n08[] PROGMEM = { 
kn08_01, kn08_02, kn08_03, kn08_04, kn08_05, kn08_06, kn08_07, kn08_08, 
kn08_09, kn08_10, kn08_11, kn08_12, kn08_13, kn08_14, kn08_15, (uint8_t *)0 };
const uint32_t * const kpg_f08[] PROGMEM = { 
kf08_01, kf08_02, kf08_03, kf08_04, kf08_05, kf08_06, kf08_07, kf08_08, 
kf08_09, kf08_10, kf08_11, kf08_12, kf08_13, kf08_14, kf08_15 };
const uint8_t kpg_j08[] PROGMEM = { 
K_S(kf08_01), K_S(kf08_02), K_S(kf08_03), K_S(kf08_04), K_S(kf08_05), K_S(kf08_06), K_S(kf08_07), K_S(kf08_08), 
K_S(kf08_09), K_S(kf08_10), K_S(kf08_11), K_S(kf08_12), K_S(kf08_13), K_S(kf08_14), K_S(kf08_15) };
const uint16_t kpg_t08[] PROGMEM = { 
KL08_01, KL08_02, KL08_03, KL08_04, KL08_05, KL08_06, KL08_07, KL08_08, 
KL08_09, KL08_10, KL08_11, KL08_12, KL08_13, KL08_14, KL08_15 };

//******************************************
const uint8_t kpg_09[] PROGMEM = "“–≈Ã¿“Œƒ€";

const uint8_t kn09_01[] PROGMEM = "Clonorch.sinens";
const uint32_t kf09_01[] PROGMEM = { 
K_K(425700.00), K_K(426038.89), K_K(426377.78), K_K(426716.67), 
K_K(427055.56), K_K(427394.44), K_K(427733.33), K_K(428072.22), 
K_K(428411.11), K_K(428750.00) };
#define KL09_01 ( 120 )

const uint8_t kn09_02[] PROGMEM = "Cryptocolyl.lin";
const uint32_t kf09_02[] PROGMEM = { 
K_K(409950.00), K_K(410622.22), K_K(411294.44), K_K(411966.67), 
K_K(412638.89), K_K(413311.11), K_K(413983.33), K_K(414655.56), 
K_K(415327.78), K_K(416000.00) };
#define KL09_02 ( 120 )

const uint8_t kn09_03[] PROGMEM = "Echinoporyp.rec";
const uint32_t kf09_03[] PROGMEM = { 
K_K(418550.00), K_K(419144.44), K_K(419738.89), K_K(420333.33), 
K_K(420927.78), K_K(421522.22), K_K(422116.67), K_K(422711.11), 
K_K(423305.56), K_K(423900.00) };
#define KL09_03 ( 120 )

const uint8_t kn09_04[] PROGMEM = "Echinostom.revo";
const uint32_t kf09_04[] PROGMEM = { 
K_K(425500.00), K_K(425961.11), K_K(426422.22), K_K(426883.33), 
K_K(427344.44), K_K(427805.56), K_K(428266.67), K_K(428727.78), 
K_K(429188.89), K_K(429650.00) };
#define KL09_04 ( 120 )

const uint8_t kn09_05[] PROGMEM = "Eurytrem.pancre";
const uint32_t kf09_05[] PROGMEM = { 
K_K(420350.00), K_K(420566.67), K_K(420783.33), K_K(421000.00), 
K_K(421216.67), K_K(421433.33), K_K(421650.00), K_K(421866.67), 
K_K(422083.33), K_K(422300.00) };
#define KL09_05 ( 120 )

const uint8_t kn09_06[] PROGMEM = "Fasciola hepati";
const uint32_t kf09_06[] PROGMEM = { 
K_K(421350.00), K_K(422011.11), K_K(422672.22), K_K(423333.33), 
K_K(423994.44), K_K(424655.56), K_K(425316.67), K_K(425977.78), 
K_K(426638.89), K_K(427300.00) };
#define KL09_06 ( 120 )

const uint8_t kn09_07[] PROGMEM = "Fasciol.hep.cer";
const uint32_t kf09_07[] PROGMEM = { 
K_K(423800.00), K_K(424555.56), K_K(425311.11), K_K(426066.67), 
K_K(426822.22), K_K(427577.78), K_K(428333.33), K_K(429088.89), 
K_K(429844.44), K_K(430600.00) };
#define KL09_07 ( 120 )

const uint8_t kn09_08[] PROGMEM = "Fasciol.hep.egg";
const uint32_t kf09_08[] PROGMEM = { 
K_K(422000.00), K_K(422622.22), K_K(423244.44), K_K(423866.67), 
K_K(424488.89), K_K(425111.11), K_K(425733.33), K_K(426355.56), 
K_K(426977.78), K_K(427600.00) };
#define KL09_08 ( 120 )

const uint8_t kn09_09[] PROGMEM = "Fasci.hep.mirac";
const uint32_t kf09_09[] PROGMEM = { 
K_K(421750.00), K_K(422077.78), K_K(422405.56), K_K(422733.33), 
K_K(423061.11), K_K(423388.89), K_K(423716.67), K_K(424044.44), 
K_K(424372.22), K_K(424700.00) };
#define KL09_09 ( 120 )

const uint8_t kn09_10[] PROGMEM = "Fasciol.hep.red";
const uint32_t kf09_10[] PROGMEM = { 
K_K(420600.00), K_K(421366.67), K_K(422133.33), K_K(422900.00), 
K_K(423666.67), K_K(424433.33), K_K(425200.00), K_K(425966.67), 
K_K(426733.33), K_K(427500.00) };
#define KL09_10 ( 120 )

const uint8_t kn09_11[] PROGMEM = "Fasciolop.buski";
const uint32_t kf09_11[] PROGMEM = { 
K_K(427700.00), K_K(428522.22), K_K(429344.44), K_K(430166.67), 
K_K(430988.89), K_K(431811.11), K_K(432633.33), K_K(433455.56), 
K_K(434277.78), K_K(435100.00) };
#define KL09_11 ( 120 )

const uint8_t kn09_12[] PROGMEM = "Fasciol.bus.egg";
const uint32_t kf09_12[] PROGMEM = { 
K_K(427350.00), K_K(428250.00), K_K(429150.00), K_K(430050.00), 
K_K(430950.00), K_K(431850.00), K_K(432750.00), K_K(433650.00), 
K_K(434550.00), K_K(435450.00) };
#define KL09_12 ( 120 )

const uint8_t kn09_13[] PROGMEM = "Fasciolop.cerca";
const uint32_t kf09_13[] PROGMEM = { 
K_K(429500.00), K_K(430250.00), K_K(431000.00), K_K(431750.00), 
K_K(432500.00), K_K(433250.00), K_K(434000.00), K_K(434750.00), 
K_K(435500.00), K_K(436250.00) };
#define KL09_13 ( 120 )

const uint8_t kn09_14[] PROGMEM = "Fasciolop.mirac";
const uint32_t kf09_14[] PROGMEM = { 
K_K(427350.00), K_K(428222.22), K_K(429094.44), K_K(429966.67), 
K_K(430838.89), K_K(431711.11), K_K(432583.33), K_K(433455.56), 
K_K(434327.78), K_K(435200.00) };
#define KL09_14 ( 120 )

const uint8_t kn09_15[] PROGMEM = "Fasciolop.redia";
const uint32_t kf09_15[] PROGMEM = { 
K_K(427300.00), K_K(427933.33), K_K(428566.67), K_K(429200.00), 
K_K(429833.33), K_K(430466.67), K_K(431100.00), K_K(431733.33), 
K_K(432366.67), K_K(433000.00) };
#define KL09_15 ( 120 )

const uint8_t kn09_16[] PROGMEM = "Fischoedr.elong";
const uint32_t kf09_16[] PROGMEM = { 
K_K(441750.00), K_K(441911.11), K_K(442072.22), K_K(442233.33), 
K_K(442394.44), K_K(442555.56), K_K(442716.67), K_K(442877.78), 
K_K(443038.89), K_K(443200.00) };
#define KL09_16 ( 120 )

const uint8_t kn09_17[] PROGMEM = "Gastrothy.elong";
const uint32_t kf09_17[] PROGMEM = { 
K_K(451900.00), K_K(452477.78), K_K(453055.56), K_K(453633.33), 
K_K(454211.11), K_K(454788.89), K_K(455366.67), K_K(455944.44), 
K_K(456522.22), K_K(457100.00) };
#define KL09_17 ( 120 )

const uint8_t kn09_18[] PROGMEM = "Gyrodactylus";
const uint32_t kf09_18[] PROGMEM = { 
K_K(378750.00), K_K(379088.89), K_K(379427.78), K_K(379766.67), 
K_K(380105.56), K_K(380444.44), K_K(380783.33), K_K(381122.22), 
K_K(381461.11), K_K(381800.00) };
#define KL09_18 ( 120 )

const uint8_t kn09_19[] PROGMEM = "Hasstile s.tric";
const uint32_t kf09_19[] PROGMEM = { 
K_K(448050.00), K_K(448833.33), K_K(449616.67), K_K(450400.00), 
K_K(451183.33), K_K(451966.67), K_K(452750.00), K_K(453533.33), 
K_K(454316.67), K_K(455100.00) };
#define KL09_19 ( 120 )

const uint8_t kn09_20[] PROGMEM = "Hypoder.conoide";
const uint32_t kf09_20[] PROGMEM = { 
K_K(424450.00), K_K(425016.67), K_K(425583.33), K_K(426150.00), 
K_K(426716.67), K_K(427283.33), K_K(427850.00), K_K(428416.67), 
K_K(428983.33), K_K(429550.00) };
#define KL09_20 ( 120 )

const uint8_t kn09_21[] PROGMEM = "Metagon.Yokogaw";
const uint32_t kf09_21[] PROGMEM = { 
K_K(437350.00), K_K(437877.78), K_K(438405.56), K_K(438933.33), 
K_K(439461.11), K_K(439988.89), K_K(440516.67), K_K(441044.44), 
K_K(441572.22), K_K(442100.00) };
#define KL09_21 ( 120 )

const uint8_t kn09_22[] PROGMEM = "Paragon.Westerm";
const uint32_t kf09_22[] PROGMEM = { 
K_K(437800.00), K_K(439622.22), K_K(441444.44), K_K(443266.67), 
K_K(445088.89), K_K(446911.11), K_K(448733.33), K_K(450555.56), 
K_K(452377.78), K_K(454200.00) };
#define KL09_22 ( 120 )

const uint8_t kn09_23[] PROGMEM = "Prosthogon.maer";
const uint32_t kf09_23[] PROGMEM = { 
K_K(396850.00), K_K(397727.78), K_K(398605.56), K_K(399483.33), 
K_K(400361.11), K_K(401238.89), K_K(402116.67), K_K(402994.44), 
K_K(403872.22), K_K(404750.00) };
#define KL09_23 ( 120 )

const uint8_t kn09_24[] PROGMEM = "Schistosom.haem";
const uint32_t kf09_24[] PROGMEM = { K_K(473000.00) };
#define KL09_24 ( 1200 )

const uint8_t kn09_25[] PROGMEM = "Schistosom.Mans";
const uint32_t kf09_25[] PROGMEM = { K_K(353000.00) };
#define KL09_25 ( 1200 )

const uint8_t kn09_26[] PROGMEM = "Urocleidus";
const uint32_t kf09_26[] PROGMEM = { 
K_K(442350.00), K_K(443200.00), K_K(444050.00), K_K(444900.00), 
K_K(445750.00), K_K(446600.00), K_K(447450.00), K_K(448300.00), 
K_K(449150.00), K_K(450000.00) };
#define KL09_26 ( 120 )

const uint8_t * const kpg_n09[] PROGMEM = { 
kn09_01, kn09_02, kn09_03, kn09_04, kn09_05, kn09_06, kn09_07, kn09_08, 
kn09_09, kn09_10, kn09_11, kn09_12, kn09_13, kn09_14, kn09_15, kn09_16, kn09_17, 
kn09_18, kn09_19, kn09_20, kn09_21, kn09_22, kn09_23, kn09_24, kn09_25, kn09_26, (uint8_t *)0 };
const uint32_t * const kpg_f09[] PROGMEM = { 
kf09_01, kf09_02, kf09_03, kf09_04, kf09_05, kf09_06, kf09_07, kf09_08, 
kf09_09, kf09_10, kf09_11, kf09_12, kf09_13, kf09_14, kf09_15, kf09_16, kf09_17, 
kf09_18, kf09_19, kf09_20, kf09_21, kf09_22, kf09_23, kf09_24, kf09_25, kf09_26 };
const uint8_t kpg_j09[] PROGMEM = { 
K_S(kf09_01), K_S(kf09_02), K_S(kf09_03), K_S(kf09_04), K_S(kf09_05), K_S(kf09_06), K_S(kf09_07), K_S(kf09_08), 
K_S(kf09_09), K_S(kf09_10), K_S(kf09_11), K_S(kf09_12), K_S(kf09_13), K_S(kf09_14), K_S(kf09_15), K_S(kf09_16), K_S(kf09_17), 
K_S(kf09_18), K_S(kf09_19), K_S(kf09_20), K_S(kf09_21), K_S(kf09_22), K_S(kf09_23), K_S(kf09_24), K_S(kf09_25), K_S(kf09_26) };
const uint16_t kpg_t09[] PROGMEM = { 
KL09_01, KL09_02, KL09_03, KL09_04, KL09_05, KL09_06, KL09_07, KL09_08, 
KL09_09, KL09_10, KL09_11, KL09_12, KL09_13, KL09_14, KL09_15, KL09_16, KL09_17, 
KL09_18, KL09_19, KL09_20, KL09_21, KL09_22, KL09_23, KL09_24, KL09_25, KL09_26 };

//******************************************
const uint8_t kpg_10[] PROGMEM = "÷≈—“Œƒ€";

const uint8_t kn10_01[] PROGMEM = "Cysticerc.fasci";
const uint32_t kf10_01[] PROGMEM = { 
K_K(436400.00), K_K(436805.56), K_K(437211.11), K_K(437616.67), 
K_K(438022.22), K_K(438427.78), K_K(438833.33), K_K(439238.89), 
K_K(439644.44), K_K(440050.00) };
#define KL10_01 ( 120 )

const uint8_t kn10_02[] PROGMEM = "Diphyllob.erina";
const uint32_t kf10_02[] PROGMEM = { 
K_K(467250.00), K_K(469505.56), K_K(471761.11), K_K(474016.67), 
K_K(476272.22), K_K(478527.78), K_K(480783.33), K_K(483038.89), 
K_K(485294.45), K_K(487550.00) };
#define KL10_02 ( 120 )

const uint8_t kn10_03[] PROGMEM = "Diphyllobot.lat";
const uint32_t kf10_03[] PROGMEM = { 
K_K(452900.00), K_K(455055.56), K_K(457211.11), K_K(459366.67), 
K_K(461522.22), K_K(463677.78), K_K(465833.33), K_K(467988.89), 
K_K(470144.45), K_K(472300.00) };
#define KL10_03 ( 120 )

const uint8_t kn10_04[] PROGMEM = "Dipylidi.caninu";
const uint32_t kf10_04[] PROGMEM = { 
K_K(439550.00), K_K(440077.78), K_K(440605.56), K_K(441133.33), 
K_K(441661.11), K_K(442188.89), K_K(442716.67), K_K(443244.44), 
K_K(443772.22), K_K(444300.00) };
#define KL10_04 ( 120 )

const uint8_t kn10_05[] PROGMEM = "Dipylidi.cani.h";
const uint32_t kf10_05[] PROGMEM = { 
K_K(451950.00), K_K(454194.44), K_K(456438.89), K_K(458683.33), 
K_K(460927.78), K_K(463172.22), K_K(465416.67), K_K(467661.11), 
K_K(469905.55), K_K(472150.00) };
#define KL10_05 ( 120 )

const uint8_t kn10_06[] PROGMEM = "Echinococ.granu";
const uint32_t kf10_06[] PROGMEM = { 
K_K(441150.00), K_K(441744.44), K_K(442338.89), K_K(442933.33), 
K_K(443527.78), K_K(444122.22), K_K(444716.67), K_K(445311.11), 
K_K(445905.56), K_K(446500.00) };
#define KL10_06 ( 120 )

const uint8_t kn10_07[] PROGMEM = "Echinoc.granul2";
const uint32_t kf10_07[] PROGMEM = { 
K_K(451600.00), K_K(452700.00), K_K(453800.00), K_K(454900.00), 
K_K(456000.00), K_K(457100.00), K_K(458200.00), K_K(459300.00), 
K_K(460400.00), K_K(461500.00) };
#define KL10_07 ( 120 )

const uint8_t kn10_08[] PROGMEM = "Echinoc.multilo";
const uint32_t kf10_08[] PROGMEM = { 
K_K(455850.00), K_K(456127.78), K_K(456405.56), K_K(456683.33), 
K_K(456961.11), K_K(457238.89), K_K(457516.67), K_K(457794.44), 
K_K(458072.22), K_K(458350.00) };
#define KL10_08 ( 120 )

const uint8_t kn10_09[] PROGMEM = "Hymenolep.cysti";
const uint32_t kf10_09[] PROGMEM = { 
K_K(478000.00), K_K(478416.67), K_K(478833.33), K_K(479250.00), 
K_K(479666.67), K_K(480083.33), K_K(480500.00), K_K(480916.67), 
K_K(481333.33), K_K(481750.00) };
#define KL10_09 ( 120 )

const uint8_t kn10_10[] PROGMEM = "Hymenolep.dimin";
const uint32_t kf10_10[] PROGMEM = { 
K_K(445000.00), K_K(449016.67), K_K(453033.33), K_K(457050.00), 
K_K(461066.67), K_K(465083.33), K_K(469100.00), K_K(473116.67), 
K_K(477133.33), K_K(481150.00) };
#define KL10_10 ( 120 )

const uint8_t kn10_11[] PROGMEM = "Moniezia(scolex";
const uint32_t kf10_11[] PROGMEM = { 
K_K(430350.00), K_K(434222.22), K_K(438094.44), K_K(441966.67), 
K_K(445838.89), K_K(449711.11), K_K(453583.33), K_K(457455.56), 
K_K(461327.78), K_K(465200.00) };
#define KL10_11 ( 120 )

const uint8_t kn10_12[] PROGMEM = "Moniezia expans";
const uint32_t kf10_12[] PROGMEM = { 
K_K(430350.00), K_K(434222.22), K_K(438094.44), K_K(441966.67), 
K_K(445838.89), K_K(449711.11), K_K(453583.33), K_K(457455.56), 
K_K(461327.78), K_K(465200.00) };
#define KL10_12 ( 120 )

const uint8_t kn10_13[] PROGMEM = "Multicep.serial";
const uint32_t kf10_13[] PROGMEM = { 
K_K(453600.00), K_K(454066.67), K_K(454533.33), K_K(455000.00), 
K_K(455466.67), K_K(455933.33), K_K(456400.00), K_K(456866.67), 
K_K(457333.33), K_K(457800.00) };
#define KL10_13 ( 120 )

const uint8_t kn10_14[] PROGMEM = "Taen.pisifor.eg";
const uint32_t kf10_14[] PROGMEM = { 
K_K(465200.00), K_K(465700.00), K_K(466200.00), K_K(466700.00), 
K_K(467200.00), K_K(467700.00), K_K(468200.00), K_K(468700.00), 
K_K(469200.00), K_K(469700.00) };
#define KL10_14 ( 120 )

const uint8_t kn10_15[] PROGMEM = "Taen.pisif.cyst";
const uint32_t kf10_15[] PROGMEM = { 
K_K(475200.00), K_K(475966.67), K_K(476733.33), K_K(477500.00), 
K_K(478266.67), K_K(479033.33), K_K(479800.00), K_K(480566.67), 
K_K(481333.33), K_K(482100.00) };
#define KL10_15 ( 120 )

const uint8_t kn10_16[] PROGMEM = "Taen.sagin.cyst";
const uint32_t kf10_16[] PROGMEM = { 
K_K(476500.00), K_K(477005.56), K_K(477511.11), K_K(478016.67), 
K_K(478522.22), K_K(479027.78), K_K(479533.33), K_K(480038.89), 
K_K(480544.44), K_K(481050.00) };
#define KL10_16 ( 120 )

const uint8_t kn10_17[] PROGMEM = "Taen.soliu.cyst";
const uint32_t kf10_17[] PROGMEM = { K_K(475000.00) };
#define KL10_17 ( 1200 )

const uint8_t kn10_18[] PROGMEM = "Taen.soliu.scol";
const uint32_t kf10_18[] PROGMEM = { 
K_K(444000.00), K_K(444544.44), K_K(445088.89), K_K(445633.33), 
K_K(446177.78), K_K(446722.22), K_K(447266.67), K_K(447811.11), 
K_K(448355.56), K_K(448900.00) };
#define KL10_18 ( 120 )

const uint8_t * const kpg_n10[] PROGMEM = { 
kn10_01, kn10_02, kn10_03, kn10_04, kn10_05, kn10_06, kn10_07, kn10_08, 
kn10_09, kn10_10, kn10_11, kn10_12, kn10_13, kn10_14, kn10_15, kn10_16, kn10_17, kn10_18, (uint8_t *)0 };
const uint32_t * const kpg_f10[] PROGMEM = { 
kf10_01, kf10_02, kf10_03, kf10_04, kf10_05, kf10_06, kf10_07, kf10_08, 
kf10_09, kf10_10, kf10_11, kf10_12, kf10_13, kf10_14, kf10_15, kf10_16, kf10_17, kf10_18 };
const uint8_t kpg_j10[] PROGMEM = { 
K_S(kf10_01), K_S(kf10_02), K_S(kf10_03), K_S(kf10_04), K_S(kf10_05), K_S(kf10_06), K_S(kf10_07), K_S(kf10_08), 
K_S(kf10_09), K_S(kf10_10), K_S(kf10_11), K_S(kf10_12), K_S(kf10_13), K_S(kf10_14), K_S(kf10_15), K_S(kf10_16), K_S(kf10_17), K_S(kf10_18) };
const uint16_t kpg_t10[] PROGMEM = { 
KL10_01, KL10_02, KL10_03, KL10_04, KL10_05, KL10_06, KL10_07, KL10_08, 
KL10_09, KL10_10, KL10_11, KL10_12, KL10_13, KL10_14, KL10_15, KL10_16, KL10_17, KL10_18 };

//******************************************
const uint8_t kpg_11[] PROGMEM = " À≈Ÿ»";

const uint8_t kn11_01[] PROGMEM = "Demodex follic";
const uint32_t kf11_01[] PROGMEM = { K_K(682000.00) };
#define KL11_01 ( 1200 )

const uint8_t kn11_02[] PROGMEM = "Dermatophag.dus";
const uint32_t kf11_02[] PROGMEM = { K_K(707000.00) };
#define KL11_02 ( 1200 )

const uint8_t kn11_03[] PROGMEM = "Meal mite";
const uint32_t kf11_03[] PROGMEM = { K_K(718000.00) };
#define KL11_03 ( 1200 )

const uint8_t kn11_04[] PROGMEM = "Omithonys.bird";
const uint32_t kf11_04[] PROGMEM = { 
K_K(877000.00), K_K(877111.11), K_K(877222.22), K_K(877333.33), 
K_K(877444.44), K_K(877555.56), K_K(877666.67), K_K(877777.78), 
K_K(877888.89), K_K(878000.00) };
#define KL11_04 ( 120 )

const uint8_t kn11_05[] PROGMEM = "Sarcopt.scabei";
const uint32_t kf11_05[] PROGMEM = { K_K(735000.00) };
#define KL11_05 ( 1200 )

const uint8_t * const kpg_n11[] PROGMEM = { kn11_01, kn11_02, kn11_03, kn11_04, kn11_05, (uint8_t *)0 };
const uint32_t * const kpg_f11[] PROGMEM = { kf11_01, kf11_02, kf11_03, kf11_04, kf11_05 };
const uint8_t kpg_j11[] PROGMEM = { K_S(kf11_01), K_S(kf11_02), K_S(kf11_03), K_S(kf11_04), K_S(kf11_05) };
const uint16_t kpg_t11[] PROGMEM = { KL11_01, KL11_02, KL11_03, KL11_04, KL11_05 };

//******************************************
const uint8_t kpg_12[] PROGMEM = "œ–Œ◊»≈";

const uint8_t kn12_01[] PROGMEM = "Blepharisma";
const uint32_t kf12_01[] PROGMEM = { 
K_K(405650.00), K_K(405850.00), K_K(406050.00), K_K(406250.00), 
K_K(406450.00), K_K(406650.00), K_K(406850.00), K_K(407050.00), 
K_K(407250.00), K_K(407450.00) };
#define KL12_01 ( 120 )

const uint8_t kn12_02[] PROGMEM = "Eikanella corro";
const uint32_t kf12_02[] PROGMEM = { 
K_K(379500.00), K_K(380033.33), K_K(380566.67), K_K(381100.00), 
K_K(381633.33), K_K(382166.67), K_K(382700.00), K_K(383233.33), 
K_K(383766.67), K_K(384300.00) };
#define KL12_02 ( 120 )

const uint8_t kn12_03[] PROGMEM = "Macracanthorhyn";
const uint32_t kf12_03[] PROGMEM = { 
K_K(438850.00), K_K(439288.89), K_K(439727.78), K_K(440166.67), 
K_K(440605.56), K_K(441044.44), K_K(441483.33), K_K(441922.22), 
K_K(442361.11), K_K(442800.00) };
#define KL12_03 ( 120 )

const uint8_t kn12_04[] PROGMEM = "Stigeoclonium";
const uint32_t kf12_04[] PROGMEM = { 
K_K(404250.00), K_K(405472.22), K_K(406694.44), K_K(407916.67), 
K_K(409138.89), K_K(410361.11), K_K(411583.33), K_K(412805.56), 
K_K(414027.78), K_K(415250.00) };
#define KL12_04 ( 120 )

const uint8_t kn12_05[] PROGMEM = "Troglodyt.abras";
const uint32_t kf12_05[] PROGMEM = { 
K_K(377750.00), K_K(378577.78), K_K(379405.56), K_K(380233.33), 
K_K(381061.11), K_K(381888.89), K_K(382716.67), K_K(383544.44), 
K_K(384372.22), K_K(385200.00) };
#define KL12_05 ( 120 )

const uint8_t kn12_06[] PROGMEM = "Troglod.abrass2";
const uint32_t kf12_06[] PROGMEM = { 
K_K(416900.00), K_K(417488.89), K_K(418077.78), K_K(418666.67), 
K_K(419255.56), K_K(419844.44), K_K(420433.33), K_K(421022.22), 
K_K(421611.11), K_K(422200.00) };
#define KL12_06 ( 120 )

const uint8_t * const kpg_n12[] PROGMEM = { kn12_01, kn12_02, kn12_03, kn12_04, kn12_05, kn12_06, (uint8_t *)0 };
const uint32_t * const kpg_f12[] PROGMEM = { kf12_01, kf12_02, kf12_03, kf12_04, kf12_05, kf12_06 };
const uint8_t kpg_j12[] PROGMEM = { K_S(kf12_01), K_S(kf12_02), K_S(kf12_03), K_S(kf12_04), K_S(kf12_05), K_S(kf12_06) };
const uint16_t kpg_t12[] PROGMEM = { KL12_01, KL12_02, KL12_03, KL12_04, KL12_05, KL12_06 };


//*******************************************
const uint8_t * const kpg_menu[] PROGMEM = { 
kpg_01, kpg_02, kpg_03, kpg_04, kpg_05, kpg_06, kpg_07, kpg_08, 
kpg_09, kpg_10, kpg_11, kpg_12, (uint8_t *)0 };

const uint16_t kpg_names[] PROGMEM = { 
K_P(kpg_n01), K_P(kpg_n02), K_P(kpg_n03), K_P(kpg_n04), K_P(kpg_n05), K_P(kpg_n06), K_P(kpg_n07), K_P(kpg_n08), 
K_P(kpg_n09), K_P(kpg_n10), K_P(kpg_n11), K_P(kpg_n12) };

const uint16_t kpg_freqs[] PROGMEM = { 
K_P(kpg_f01), K_P(kpg_f02), K_P(kpg_f03), K_P(kpg_f04), K_P(kpg_f05), K_P(kpg_f06), K_P(kpg_f07), K_P(kpg_f08), 
K_P(kpg_f09), K_P(kpg_f10), K_P(kpg_f11), K_P(kpg_f12) };

const uint16_t kpg_nums[] PROGMEM = { 
K_P(kpg_j01), K_P(kpg_j02), K_P(kpg_j03), K_P(kpg_j04), K_P(kpg_j05), K_P(kpg_j06), K_P(kpg_j07), K_P(kpg_j08), 
K_P(kpg_j09), K_P(kpg_j10), K_P(kpg_j11), K_P(kpg_j12) };

const uint16_t kpg_secs[] PROGMEM = { 
K_P(kpg_t01), K_P(kpg_t02), K_P(kpg_t03), K_P(kpg_t04), K_P(kpg_t05), K_P(kpg_t06), K_P(kpg_t07), K_P(kpg_t08), 
K_P(kpg_t09), K_P(kpg_t10), K_P(kpg_t11), K_P(kpg_t12) };




#define razdel_knames( razdel )		( (uint16_t *)pgm_read_word( &kpg_names[ razdel ] ) )
#define razdel_knums( razdel )		( (uint8_t *)pgm_read_word( &kpg_nums[ razdel ] ) )
#define razdel_ksecs( razdel )		( (uint16_t *)pgm_read_word( &kpg_secs[ razdel ] ) )
#define razdel_kfreqs( razdel )		( (uint16_t *)pgm_read_word( &kpg_freqs[ razdel ] ) )


#define prog_kname( razdel, i )		( (uint8_t *)pgm_read_word( &razdel_knames( razdel )[i] ) )
#define prog_ksec( razdel, i )		( (uint16_t)pgm_read_word( &razdel_ksecs( razdel )[i] ) )
#define prog_knum( razdel, i )		( (uint8_t)pgm_read_byte( &razdel_knums( razdel )[i] ) )
#define prog_kfreqs( razdel, i )	( (uint32_t *)pgm_read_word( &razdel_kfreqs( razdel )[i] ) )


#endif
