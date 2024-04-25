; ModuleID = 'marshal_methods.x86.ll'
source_filename = "marshal_methods.x86.ll"
target datalayout = "e-m:e-p:32:32-p270:32:32-p271:32:32-p272:64:64-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i686-unknown-linux-android21"

%struct.MarshalMethodName = type {
	i64, ; uint64_t id
	ptr ; char* name
}

%struct.MarshalMethodsManagedClass = type {
	i32, ; uint32_t token
	ptr ; MonoClass klass
}

@assembly_image_cache = dso_local local_unnamed_addr global [325 x ptr] zeroinitializer, align 4

; Each entry maps hash of an assembly name to an index into the `assembly_image_cache` array
@assembly_image_cache_hashes = dso_local local_unnamed_addr constant [644 x i32] [
	i32 2616222, ; 0: System.Net.NetworkInformation.dll => 0x27eb9e => 67
	i32 10166715, ; 1: System.Net.NameResolution.dll => 0x9b21bb => 66
	i32 15721112, ; 2: System.Runtime.Intrinsics.dll => 0xefe298 => 107
	i32 32687329, ; 3: Xamarin.AndroidX.Lifecycle.Runtime => 0x1f2c4e1 => 244
	i32 34715100, ; 4: Xamarin.Google.Guava.ListenableFuture.dll => 0x211b5dc => 278
	i32 34839235, ; 5: System.IO.FileSystem.DriveInfo => 0x2139ac3 => 47
	i32 39485524, ; 6: System.Net.WebSockets.dll => 0x25a8054 => 79
	i32 42639949, ; 7: System.Threading.Thread => 0x28aa24d => 144
	i32 53857724, ; 8: ca/Microsoft.Maui.Controls.resources => 0x335cdbc => 287
	i32 66541672, ; 9: System.Diagnostics.StackTrace => 0x3f75868 => 29
	i32 68219467, ; 10: System.Security.Cryptography.Primitives => 0x410f24b => 123
	i32 72070932, ; 11: Microsoft.Maui.Graphics.dll => 0x44bb714 => 192
	i32 82292897, ; 12: System.Runtime.CompilerServices.VisualC.dll => 0x4e7b0a1 => 101
	i32 98325684, ; 13: Microsoft.Extensions.Diagnostics.Abstractions => 0x5dc54b4 => 179
	i32 101534019, ; 14: Xamarin.AndroidX.SlidingPaneLayout => 0x60d4943 => 262
	i32 113429830, ; 15: zh-HK/Microsoft.Maui.Controls.resources => 0x6c2cd46 => 317
	i32 117431740, ; 16: System.Runtime.InteropServices => 0x6ffddbc => 106
	i32 120558881, ; 17: Xamarin.AndroidX.SlidingPaneLayout.dll => 0x72f9521 => 262
	i32 122350210, ; 18: System.Threading.Channels.dll => 0x74aea82 => 138
	i32 134690465, ; 19: Xamarin.Kotlin.StdLib.Jdk7.dll => 0x80736a1 => 282
	i32 142721839, ; 20: System.Net.WebHeaderCollection => 0x881c32f => 76
	i32 149972175, ; 21: System.Security.Cryptography.Primitives.dll => 0x8f064cf => 123
	i32 159306688, ; 22: System.ComponentModel.Annotations => 0x97ed3c0 => 13
	i32 165246403, ; 23: Xamarin.AndroidX.Collection.dll => 0x9d975c3 => 218
	i32 172961045, ; 24: Syncfusion.Maui.Core.dll => 0xa4f2d15 => 199
	i32 176265551, ; 25: System.ServiceProcess => 0xa81994f => 131
	i32 182336117, ; 26: Xamarin.AndroidX.SwipeRefreshLayout.dll => 0xade3a75 => 264
	i32 184328833, ; 27: System.ValueTuple.dll => 0xafca281 => 150
	i32 195452805, ; 28: vi/Microsoft.Maui.Controls.resources.dll => 0xba65f85 => 316
	i32 199333315, ; 29: zh-HK/Microsoft.Maui.Controls.resources.dll => 0xbe195c3 => 317
	i32 205061960, ; 30: System.ComponentModel => 0xc38ff48 => 18
	i32 209399409, ; 31: Xamarin.AndroidX.Browser.dll => 0xc7b2e71 => 216
	i32 220171995, ; 32: System.Diagnostics.Debug => 0xd1f8edb => 26
	i32 221958352, ; 33: Microsoft.Extensions.Diagnostics.dll => 0xd3ad0d0 => 178
	i32 230216969, ; 34: Xamarin.AndroidX.Legacy.Support.Core.Utils.dll => 0xdb8d509 => 238
	i32 230752869, ; 35: Microsoft.CSharp.dll => 0xdc10265 => 1
	i32 231409092, ; 36: System.Linq.Parallel => 0xdcb05c4 => 58
	i32 231814094, ; 37: System.Globalization => 0xdd133ce => 41
	i32 246610117, ; 38: System.Reflection.Emit.Lightweight => 0xeb2f8c5 => 90
	i32 261689757, ; 39: Xamarin.AndroidX.ConstraintLayout.dll => 0xf99119d => 221
	i32 276479776, ; 40: System.Threading.Timer.dll => 0x107abf20 => 146
	i32 278686392, ; 41: Xamarin.AndroidX.Lifecycle.LiveData.dll => 0x109c6ab8 => 240
	i32 280482487, ; 42: Xamarin.AndroidX.Interpolator => 0x10b7d2b7 => 237
	i32 280992041, ; 43: cs/Microsoft.Maui.Controls.resources.dll => 0x10bf9929 => 288
	i32 291076382, ; 44: System.IO.Pipes.AccessControl.dll => 0x1159791e => 53
	i32 291275502, ; 45: Microsoft.Extensions.Http.dll => 0x115c82ee => 180
	i32 298918909, ; 46: System.Net.Ping.dll => 0x11d123fd => 68
	i32 318968648, ; 47: Xamarin.AndroidX.Activity.dll => 0x13031348 => 207
	i32 321597661, ; 48: System.Numerics => 0x132b30dd => 82
	i32 336156722, ; 49: ja/Microsoft.Maui.Controls.resources.dll => 0x14095832 => 301
	i32 342366114, ; 50: Xamarin.AndroidX.Lifecycle.Common => 0x146817a2 => 239
	i32 347068432, ; 51: SQLitePCLRaw.lib.e_sqlite3.android.dll => 0x14afd810 => 196
	i32 354584097, ; 52: en-US/Syncfusion.Maui.Popup.resources.dll => 0x15228621 => 320
	i32 356389973, ; 53: it/Microsoft.Maui.Controls.resources.dll => 0x153e1455 => 300
	i32 357576608, ; 54: cs/Microsoft.Maui.Controls.resources => 0x15502fa0 => 288
	i32 360082299, ; 55: System.ServiceModel.Web => 0x15766b7b => 130
	i32 367780167, ; 56: System.IO.Pipes => 0x15ebe147 => 54
	i32 374376850, ; 57: Syncfusion.Maui.Popup.dll => 0x16508992 => 201
	i32 374914964, ; 58: System.Transactions.Local => 0x1658bf94 => 148
	i32 375677976, ; 59: System.Net.ServicePoint.dll => 0x16646418 => 73
	i32 379916513, ; 60: System.Threading.Thread.dll => 0x16a510e1 => 144
	i32 385762202, ; 61: System.Memory.dll => 0x16fe439a => 61
	i32 392610295, ; 62: System.Threading.ThreadPool.dll => 0x1766c1f7 => 145
	i32 395744057, ; 63: _Microsoft.Android.Resource.Designer => 0x17969339 => 321
	i32 403441872, ; 64: WindowsBase => 0x180c08d0 => 164
	i32 435591531, ; 65: sv/Microsoft.Maui.Controls.resources.dll => 0x19f6996b => 312
	i32 441335492, ; 66: Xamarin.AndroidX.ConstraintLayout.Core => 0x1a4e3ec4 => 222
	i32 442565967, ; 67: System.Collections => 0x1a61054f => 12
	i32 450948140, ; 68: Xamarin.AndroidX.Fragment.dll => 0x1ae0ec2c => 235
	i32 451504562, ; 69: System.Security.Cryptography.X509Certificates => 0x1ae969b2 => 124
	i32 456227837, ; 70: System.Web.HttpUtility.dll => 0x1b317bfd => 151
	i32 459347974, ; 71: System.Runtime.Serialization.Primitives.dll => 0x1b611806 => 112
	i32 465846621, ; 72: mscorlib => 0x1bc4415d => 165
	i32 469710990, ; 73: System.dll => 0x1bff388e => 163
	i32 476646585, ; 74: Xamarin.AndroidX.Interpolator.dll => 0x1c690cb9 => 237
	i32 486930444, ; 75: Xamarin.AndroidX.LocalBroadcastManager.dll => 0x1d05f80c => 250
	i32 498788369, ; 76: System.ObjectModel => 0x1dbae811 => 83
	i32 500358224, ; 77: id/Microsoft.Maui.Controls.resources.dll => 0x1dd2dc50 => 299
	i32 503918385, ; 78: fi/Microsoft.Maui.Controls.resources.dll => 0x1e092f31 => 293
	i32 513247710, ; 79: Microsoft.Extensions.Primitives.dll => 0x1e9789de => 186
	i32 522421185, ; 80: en-US/Syncfusion.Maui.Popup.resources => 0x1f2383c1 => 320
	i32 526420162, ; 81: System.Transactions.dll => 0x1f6088c2 => 149
	i32 527168573, ; 82: hi/Microsoft.Maui.Controls.resources => 0x1f6bf43d => 296
	i32 527452488, ; 83: Xamarin.Kotlin.StdLib.Jdk7 => 0x1f704948 => 282
	i32 530272170, ; 84: System.Linq.Queryable => 0x1f9b4faa => 59
	i32 539058512, ; 85: Microsoft.Extensions.Logging => 0x20216150 => 181
	i32 540030774, ; 86: System.IO.FileSystem.dll => 0x20303736 => 50
	i32 545304856, ; 87: System.Runtime.Extensions => 0x2080b118 => 102
	i32 546455878, ; 88: System.Runtime.Serialization.Xml => 0x20924146 => 113
	i32 549171840, ; 89: System.Globalization.Calendars => 0x20bbb280 => 39
	i32 557405415, ; 90: Jsr305Binding => 0x213954e7 => 275
	i32 569601784, ; 91: Xamarin.AndroidX.Window.Extensions.Core.Core => 0x21f36ef8 => 273
	i32 577335427, ; 92: System.Security.Cryptography.Cng => 0x22697083 => 119
	i32 592146354, ; 93: pt-BR/Microsoft.Maui.Controls.resources.dll => 0x234b6fb2 => 307
	i32 601371474, ; 94: System.IO.IsolatedStorage.dll => 0x23d83352 => 51
	i32 605376203, ; 95: System.IO.Compression.FileSystem => 0x24154ecb => 43
	i32 613668793, ; 96: System.Security.Cryptography.Algorithms => 0x2493d7b9 => 118
	i32 627609679, ; 97: Xamarin.AndroidX.CustomView => 0x2568904f => 227
	i32 639843206, ; 98: Xamarin.AndroidX.Emoji2.ViewsHelper.dll => 0x26233b86 => 233
	i32 643868501, ; 99: System.Net => 0x2660a755 => 80
	i32 662205335, ; 100: System.Text.Encodings.Web.dll => 0x27787397 => 135
	i32 663517072, ; 101: Xamarin.AndroidX.VersionedParcelable => 0x278c7790 => 269
	i32 666292255, ; 102: Xamarin.AndroidX.Arch.Core.Common.dll => 0x27b6d01f => 214
	i32 672442732, ; 103: System.Collections.Concurrent => 0x2814a96c => 8
	i32 683518922, ; 104: System.Net.Security => 0x28bdabca => 72
	i32 688181140, ; 105: ca/Microsoft.Maui.Controls.resources.dll => 0x2904cf94 => 287
	i32 690569205, ; 106: System.Xml.Linq.dll => 0x29293ff5 => 154
	i32 691348768, ; 107: Xamarin.KotlinX.Coroutines.Android.dll => 0x29352520 => 284
	i32 693804605, ; 108: System.Windows => 0x295a9e3d => 153
	i32 695450347, ; 109: Syncfusion.Maui.Popup => 0x2973baeb => 201
	i32 699345723, ; 110: System.Reflection.Emit => 0x29af2b3b => 91
	i32 700284507, ; 111: Xamarin.Jetbrains.Annotations => 0x29bd7e5b => 279
	i32 700358131, ; 112: System.IO.Compression.ZipFile => 0x29be9df3 => 44
	i32 706645707, ; 113: ko/Microsoft.Maui.Controls.resources.dll => 0x2a1e8ecb => 302
	i32 709557578, ; 114: de/Microsoft.Maui.Controls.resources.dll => 0x2a4afd4a => 290
	i32 720511267, ; 115: Xamarin.Kotlin.StdLib.Jdk8 => 0x2af22123 => 283
	i32 722857257, ; 116: System.Runtime.Loader.dll => 0x2b15ed29 => 108
	i32 731701662, ; 117: Microsoft.Extensions.Options.ConfigurationExtensions => 0x2b9ce19e => 185
	i32 735137430, ; 118: System.Security.SecureString.dll => 0x2bd14e96 => 128
	i32 748832960, ; 119: SQLitePCLRaw.batteries_v2 => 0x2ca248c0 => 194
	i32 752232764, ; 120: System.Diagnostics.Contracts.dll => 0x2cd6293c => 25
	i32 755313932, ; 121: Xamarin.Android.Glide.Annotations.dll => 0x2d052d0c => 204
	i32 759454413, ; 122: System.Net.Requests => 0x2d445acd => 71
	i32 762598435, ; 123: System.IO.Pipes.dll => 0x2d745423 => 54
	i32 775507847, ; 124: System.IO.Compression => 0x2e394f87 => 45
	i32 789151979, ; 125: Microsoft.Extensions.Options => 0x2f0980eb => 184
	i32 790371945, ; 126: Xamarin.AndroidX.CustomView.PoolingContainer.dll => 0x2f1c1e69 => 228
	i32 804715423, ; 127: System.Data.Common => 0x2ff6fb9f => 22
	i32 807930345, ; 128: Xamarin.AndroidX.Lifecycle.LiveData.Core.Ktx.dll => 0x302809e9 => 242
	i32 823281589, ; 129: System.Private.Uri.dll => 0x311247b5 => 85
	i32 830298997, ; 130: System.IO.Compression.Brotli => 0x317d5b75 => 42
	i32 832635846, ; 131: System.Xml.XPath.dll => 0x31a103c6 => 159
	i32 834051424, ; 132: System.Net.Quic => 0x31b69d60 => 70
	i32 843511501, ; 133: Xamarin.AndroidX.Print => 0x3246f6cd => 255
	i32 870878177, ; 134: ar/Microsoft.Maui.Controls.resources => 0x33e88be1 => 286
	i32 873119928, ; 135: Microsoft.VisualBasic => 0x340ac0b8 => 3
	i32 877678880, ; 136: System.Globalization.dll => 0x34505120 => 41
	i32 878954865, ; 137: System.Net.Http.Json => 0x3463c971 => 62
	i32 904024072, ; 138: System.ComponentModel.Primitives.dll => 0x35e25008 => 16
	i32 911108515, ; 139: System.IO.MemoryMappedFiles.dll => 0x364e69a3 => 52
	i32 923841322, ; 140: Syncfusion.Maui.Picker => 0x3710b32a => 200
	i32 926902833, ; 141: tr/Microsoft.Maui.Controls.resources.dll => 0x373f6a31 => 314
	i32 928116545, ; 142: Xamarin.Google.Guava.ListenableFuture => 0x3751ef41 => 278
	i32 929110701, ; 143: lab1.dll => 0x37611aad => 0
	i32 952186615, ; 144: System.Runtime.InteropServices.JavaScript.dll => 0x38c136f7 => 104
	i32 956575887, ; 145: Xamarin.Kotlin.StdLib.Jdk8.dll => 0x3904308f => 283
	i32 966729478, ; 146: Xamarin.Google.Crypto.Tink.Android => 0x399f1f06 => 276
	i32 967690846, ; 147: Xamarin.AndroidX.Lifecycle.Common.dll => 0x39adca5e => 239
	i32 975236339, ; 148: System.Diagnostics.Tracing => 0x3a20ecf3 => 33
	i32 975874589, ; 149: System.Xml.XDocument => 0x3a2aaa1d => 157
	i32 986514023, ; 150: System.Private.DataContractSerialization.dll => 0x3acd0267 => 84
	i32 987214855, ; 151: System.Diagnostics.Tools => 0x3ad7b407 => 31
	i32 992768348, ; 152: System.Collections.dll => 0x3b2c715c => 12
	i32 993161700, ; 153: zh-Hans/Microsoft.Maui.Controls.resources => 0x3b3271e4 => 318
	i32 994442037, ; 154: System.IO.FileSystem => 0x3b45fb35 => 50
	i32 994547685, ; 155: es/Microsoft.Maui.Controls.resources => 0x3b4797e5 => 292
	i32 1001831731, ; 156: System.IO.UnmanagedMemoryStream.dll => 0x3bb6bd33 => 55
	i32 1012816738, ; 157: Xamarin.AndroidX.SavedState.dll => 0x3c5e5b62 => 259
	i32 1019214401, ; 158: System.Drawing => 0x3cbffa41 => 35
	i32 1028951442, ; 159: Microsoft.Extensions.DependencyInjection.Abstractions => 0x3d548d92 => 177
	i32 1029334545, ; 160: da/Microsoft.Maui.Controls.resources.dll => 0x3d5a6611 => 289
	i32 1031528504, ; 161: Xamarin.Google.ErrorProne.Annotations.dll => 0x3d7be038 => 277
	i32 1035644815, ; 162: Xamarin.AndroidX.AppCompat => 0x3dbaaf8f => 212
	i32 1036536393, ; 163: System.Drawing.Primitives.dll => 0x3dc84a49 => 34
	i32 1044663988, ; 164: System.Linq.Expressions.dll => 0x3e444eb4 => 57
	i32 1048992957, ; 165: Microsoft.Extensions.Diagnostics.Abstractions.dll => 0x3e865cbd => 179
	i32 1052210849, ; 166: Xamarin.AndroidX.Lifecycle.ViewModel.dll => 0x3eb776a1 => 246
	i32 1067306892, ; 167: GoogleGson => 0x3f9dcf8c => 172
	i32 1082857460, ; 168: System.ComponentModel.TypeConverter => 0x408b17f4 => 17
	i32 1084122840, ; 169: Xamarin.Kotlin.StdLib => 0x409e66d8 => 280
	i32 1098259244, ; 170: System => 0x41761b2c => 163
	i32 1121599056, ; 171: Xamarin.AndroidX.Lifecycle.Runtime.Ktx.dll => 0x42da3e50 => 245
	i32 1127624469, ; 172: Microsoft.Extensions.Logging.Debug => 0x43362f15 => 183
	i32 1149092582, ; 173: Xamarin.AndroidX.Window => 0x447dc2e6 => 272
	i32 1170634674, ; 174: System.Web.dll => 0x45c677b2 => 152
	i32 1175144683, ; 175: Xamarin.AndroidX.VectorDrawable.Animated => 0x460b48eb => 268
	i32 1178241025, ; 176: Xamarin.AndroidX.Navigation.Runtime.dll => 0x463a8801 => 253
	i32 1178797549, ; 177: fi/Microsoft.Maui.Controls.resources => 0x464305ed => 293
	i32 1203215381, ; 178: pl/Microsoft.Maui.Controls.resources.dll => 0x47b79c15 => 306
	i32 1204270330, ; 179: Xamarin.AndroidX.Arch.Core.Common => 0x47c7b4fa => 214
	i32 1208641965, ; 180: System.Diagnostics.Process => 0x480a69ad => 28
	i32 1219128291, ; 181: System.IO.IsolatedStorage => 0x48aa6be3 => 51
	i32 1234928153, ; 182: nb/Microsoft.Maui.Controls.resources.dll => 0x499b8219 => 304
	i32 1243150071, ; 183: Xamarin.AndroidX.Window.Extensions.Core.Core.dll => 0x4a18f6f7 => 273
	i32 1253011324, ; 184: Microsoft.Win32.Registry => 0x4aaf6f7c => 5
	i32 1264511973, ; 185: Xamarin.AndroidX.Startup.StartupRuntime.dll => 0x4b5eebe5 => 263
	i32 1267360935, ; 186: Xamarin.AndroidX.VectorDrawable => 0x4b8a64a7 => 267
	i32 1273260888, ; 187: Xamarin.AndroidX.Collection.Ktx => 0x4be46b58 => 219
	i32 1275534314, ; 188: Xamarin.KotlinX.Coroutines.Android => 0x4c071bea => 284
	i32 1278448581, ; 189: Xamarin.AndroidX.Annotation.Jvm => 0x4c3393c5 => 211
	i32 1292207520, ; 190: SQLitePCLRaw.core.dll => 0x4d0585a0 => 195
	i32 1293217323, ; 191: Xamarin.AndroidX.DrawerLayout.dll => 0x4d14ee2b => 230
	i32 1309188875, ; 192: System.Private.DataContractSerialization => 0x4e08a30b => 84
	i32 1322716291, ; 193: Xamarin.AndroidX.Window.dll => 0x4ed70c83 => 272
	i32 1324164729, ; 194: System.Linq => 0x4eed2679 => 60
	i32 1335329327, ; 195: System.Runtime.Serialization.Json.dll => 0x4f97822f => 111
	i32 1364015309, ; 196: System.IO => 0x514d38cd => 56
	i32 1376866003, ; 197: Xamarin.AndroidX.SavedState => 0x52114ed3 => 259
	i32 1379779777, ; 198: System.Resources.ResourceManager => 0x523dc4c1 => 98
	i32 1402170036, ; 199: System.Configuration.dll => 0x53936ab4 => 19
	i32 1406073936, ; 200: Xamarin.AndroidX.CoordinatorLayout => 0x53cefc50 => 223
	i32 1408764838, ; 201: System.Runtime.Serialization.Formatters.dll => 0x53f80ba6 => 110
	i32 1411638395, ; 202: System.Runtime.CompilerServices.Unsafe => 0x5423e47b => 100
	i32 1422545099, ; 203: System.Runtime.CompilerServices.VisualC => 0x54ca50cb => 101
	i32 1434145427, ; 204: System.Runtime.Handles => 0x557b5293 => 103
	i32 1435222561, ; 205: Xamarin.Google.Crypto.Tink.Android.dll => 0x558bc221 => 276
	i32 1439761251, ; 206: System.Net.Quic.dll => 0x55d10363 => 70
	i32 1452070440, ; 207: System.Formats.Asn1.dll => 0x568cd628 => 37
	i32 1453312822, ; 208: System.Diagnostics.Tools.dll => 0x569fcb36 => 31
	i32 1457743152, ; 209: System.Runtime.Extensions.dll => 0x56e36530 => 102
	i32 1458022317, ; 210: System.Net.Security.dll => 0x56e7a7ad => 72
	i32 1461234159, ; 211: System.Collections.Immutable.dll => 0x5718a9ef => 9
	i32 1461719063, ; 212: System.Security.Cryptography.OpenSsl => 0x57201017 => 122
	i32 1462112819, ; 213: System.IO.Compression.dll => 0x57261233 => 45
	i32 1469204771, ; 214: Xamarin.AndroidX.AppCompat.AppCompatResources => 0x57924923 => 213
	i32 1470490898, ; 215: Microsoft.Extensions.Primitives => 0x57a5e912 => 186
	i32 1479771757, ; 216: System.Collections.Immutable => 0x5833866d => 9
	i32 1480492111, ; 217: System.IO.Compression.Brotli.dll => 0x583e844f => 42
	i32 1487239319, ; 218: Microsoft.Win32.Primitives => 0x58a57897 => 4
	i32 1490025113, ; 219: Xamarin.AndroidX.SavedState.SavedState.Ktx.dll => 0x58cffa99 => 260
	i32 1493001747, ; 220: hi/Microsoft.Maui.Controls.resources.dll => 0x58fd6613 => 296
	i32 1505131794, ; 221: Microsoft.Extensions.Http => 0x59b67d12 => 180
	i32 1514721132, ; 222: el/Microsoft.Maui.Controls.resources.dll => 0x5a48cf6c => 291
	i32 1536373174, ; 223: System.Diagnostics.TextWriterTraceListener => 0x5b9331b6 => 30
	i32 1543031311, ; 224: System.Text.RegularExpressions.dll => 0x5bf8ca0f => 137
	i32 1543355203, ; 225: System.Reflection.Emit.dll => 0x5bfdbb43 => 91
	i32 1550322496, ; 226: System.Reflection.Extensions.dll => 0x5c680b40 => 92
	i32 1551623176, ; 227: sk/Microsoft.Maui.Controls.resources.dll => 0x5c7be408 => 311
	i32 1554762148, ; 228: fr/Microsoft.Maui.Controls.resources => 0x5cabc9a4 => 294
	i32 1565862583, ; 229: System.IO.FileSystem.Primitives => 0x5d552ab7 => 48
	i32 1566207040, ; 230: System.Threading.Tasks.Dataflow.dll => 0x5d5a6c40 => 140
	i32 1573704789, ; 231: System.Runtime.Serialization.Json => 0x5dccd455 => 111
	i32 1580037396, ; 232: System.Threading.Overlapped => 0x5e2d7514 => 139
	i32 1580413037, ; 233: sv/Microsoft.Maui.Controls.resources => 0x5e33306d => 312
	i32 1582372066, ; 234: Xamarin.AndroidX.DocumentFile.dll => 0x5e5114e2 => 229
	i32 1591080825, ; 235: zh-Hant/Microsoft.Maui.Controls.resources => 0x5ed5f779 => 319
	i32 1592978981, ; 236: System.Runtime.Serialization.dll => 0x5ef2ee25 => 114
	i32 1597949149, ; 237: Xamarin.Google.ErrorProne.Annotations => 0x5f3ec4dd => 277
	i32 1601112923, ; 238: System.Xml.Serialization => 0x5f6f0b5b => 156
	i32 1604827217, ; 239: System.Net.WebClient => 0x5fa7b851 => 75
	i32 1618516317, ; 240: System.Net.WebSockets.Client.dll => 0x6078995d => 78
	i32 1622152042, ; 241: Xamarin.AndroidX.Loader.dll => 0x60b0136a => 249
	i32 1622358360, ; 242: System.Dynamic.Runtime => 0x60b33958 => 36
	i32 1624863272, ; 243: Xamarin.AndroidX.ViewPager2 => 0x60d97228 => 271
	i32 1635184631, ; 244: Xamarin.AndroidX.Emoji2.ViewsHelper => 0x6176eff7 => 233
	i32 1636350590, ; 245: Xamarin.AndroidX.CursorAdapter => 0x6188ba7e => 226
	i32 1639515021, ; 246: System.Net.Http.dll => 0x61b9038d => 63
	i32 1639986890, ; 247: System.Text.RegularExpressions => 0x61c036ca => 137
	i32 1641389582, ; 248: System.ComponentModel.EventBasedAsync.dll => 0x61d59e0e => 15
	i32 1657153582, ; 249: System.Runtime => 0x62c6282e => 115
	i32 1658241508, ; 250: Xamarin.AndroidX.Tracing.Tracing.dll => 0x62d6c1e4 => 265
	i32 1658251792, ; 251: Xamarin.Google.Android.Material.dll => 0x62d6ea10 => 274
	i32 1670060433, ; 252: Xamarin.AndroidX.ConstraintLayout => 0x638b1991 => 221
	i32 1675553242, ; 253: System.IO.FileSystem.DriveInfo.dll => 0x63dee9da => 47
	i32 1677501392, ; 254: System.Net.Primitives.dll => 0x63fca3d0 => 69
	i32 1678508291, ; 255: System.Net.WebSockets => 0x640c0103 => 79
	i32 1679769178, ; 256: System.Security.Cryptography => 0x641f3e5a => 125
	i32 1691477237, ; 257: System.Reflection.Metadata => 0x64d1e4f5 => 93
	i32 1696967625, ; 258: System.Security.Cryptography.Csp => 0x6525abc9 => 120
	i32 1698840827, ; 259: Xamarin.Kotlin.StdLib.Common => 0x654240fb => 281
	i32 1701541528, ; 260: System.Diagnostics.Debug.dll => 0x656b7698 => 26
	i32 1711441057, ; 261: SQLitePCLRaw.lib.e_sqlite3.android => 0x660284a1 => 196
	i32 1720223769, ; 262: Xamarin.AndroidX.Lifecycle.LiveData.Core.Ktx => 0x66888819 => 242
	i32 1726116996, ; 263: System.Reflection.dll => 0x66e27484 => 96
	i32 1728033016, ; 264: System.Diagnostics.FileVersionInfo.dll => 0x66ffb0f8 => 27
	i32 1729485958, ; 265: Xamarin.AndroidX.CardView.dll => 0x6715dc86 => 217
	i32 1736233607, ; 266: ro/Microsoft.Maui.Controls.resources.dll => 0x677cd287 => 309
	i32 1744735666, ; 267: System.Transactions.Local.dll => 0x67fe8db2 => 148
	i32 1746316138, ; 268: Mono.Android.Export => 0x6816ab6a => 168
	i32 1750313021, ; 269: Microsoft.Win32.Primitives.dll => 0x6853a83d => 4
	i32 1758240030, ; 270: System.Resources.Reader.dll => 0x68cc9d1e => 97
	i32 1763938596, ; 271: System.Diagnostics.TraceSource.dll => 0x69239124 => 32
	i32 1765942094, ; 272: System.Reflection.Extensions => 0x6942234e => 92
	i32 1766324549, ; 273: Xamarin.AndroidX.SwipeRefreshLayout => 0x6947f945 => 264
	i32 1770582343, ; 274: Microsoft.Extensions.Logging.dll => 0x6988f147 => 181
	i32 1776026572, ; 275: System.Core.dll => 0x69dc03cc => 21
	i32 1777075843, ; 276: System.Globalization.Extensions.dll => 0x69ec0683 => 40
	i32 1780572499, ; 277: Mono.Android.Runtime.dll => 0x6a216153 => 169
	i32 1788241197, ; 278: Xamarin.AndroidX.Fragment => 0x6a96652d => 235
	i32 1808609942, ; 279: Xamarin.AndroidX.Loader => 0x6bcd3296 => 249
	i32 1809966115, ; 280: nb/Microsoft.Maui.Controls.resources => 0x6be1e423 => 304
	i32 1813058853, ; 281: Xamarin.Kotlin.StdLib.dll => 0x6c111525 => 280
	i32 1813201214, ; 282: Xamarin.Google.Android.Material => 0x6c13413e => 274
	i32 1818569960, ; 283: Xamarin.AndroidX.Navigation.UI.dll => 0x6c652ce8 => 254
	i32 1818787751, ; 284: Microsoft.VisualBasic.Core => 0x6c687fa7 => 2
	i32 1821794637, ; 285: hu/Microsoft.Maui.Controls.resources => 0x6c96614d => 298
	i32 1824175904, ; 286: System.Text.Encoding.Extensions => 0x6cbab720 => 133
	i32 1824722060, ; 287: System.Runtime.Serialization.Formatters => 0x6cc30c8c => 110
	i32 1828688058, ; 288: Microsoft.Extensions.Logging.Abstractions.dll => 0x6cff90ba => 182
	i32 1842015223, ; 289: uk/Microsoft.Maui.Controls.resources.dll => 0x6dcaebf7 => 315
	i32 1847515442, ; 290: Xamarin.Android.Glide.Annotations => 0x6e1ed932 => 204
	i32 1858542181, ; 291: System.Linq.Expressions => 0x6ec71a65 => 57
	i32 1870277092, ; 292: System.Reflection.Primitives => 0x6f7a29e4 => 94
	i32 1879696579, ; 293: System.Formats.Tar.dll => 0x7009e4c3 => 38
	i32 1885316902, ; 294: Xamarin.AndroidX.Arch.Core.Runtime.dll => 0x705fa726 => 215
	i32 1888955245, ; 295: System.Diagnostics.Contracts => 0x70972b6d => 25
	i32 1889954781, ; 296: System.Reflection.Metadata.dll => 0x70a66bdd => 93
	i32 1898237753, ; 297: System.Reflection.DispatchProxy => 0x7124cf39 => 88
	i32 1900610850, ; 298: System.Resources.ResourceManager.dll => 0x71490522 => 98
	i32 1910275211, ; 299: System.Collections.NonGeneric.dll => 0x71dc7c8b => 10
	i32 1939592360, ; 300: System.Private.Xml.Linq => 0x739bd4a8 => 86
	i32 1956758971, ; 301: System.Resources.Writer => 0x74a1c5bb => 99
	i32 1960264639, ; 302: ja/Microsoft.Maui.Controls.resources => 0x74d743bf => 301
	i32 1961813231, ; 303: Xamarin.AndroidX.Security.SecurityCrypto.dll => 0x74eee4ef => 261
	i32 1968388702, ; 304: Microsoft.Extensions.Configuration.dll => 0x75533a5e => 173
	i32 1983156543, ; 305: Xamarin.Kotlin.StdLib.Common.dll => 0x7634913f => 281
	i32 1985761444, ; 306: Xamarin.Android.Glide.GifDecoder => 0x765c50a4 => 206
	i32 2011961780, ; 307: System.Buffers.dll => 0x77ec19b4 => 7
	i32 2014344398, ; 308: hr/Microsoft.Maui.Controls.resources => 0x781074ce => 297
	i32 2019465201, ; 309: Xamarin.AndroidX.Lifecycle.ViewModel => 0x785e97f1 => 246
	i32 2025202353, ; 310: ar/Microsoft.Maui.Controls.resources.dll => 0x78b622b1 => 286
	i32 2031763787, ; 311: Xamarin.Android.Glide => 0x791a414b => 203
	i32 2043674646, ; 312: it/Microsoft.Maui.Controls.resources => 0x79d00016 => 300
	i32 2045470958, ; 313: System.Private.Xml => 0x79eb68ee => 87
	i32 2048278909, ; 314: Microsoft.Extensions.Configuration.Binder.dll => 0x7a16417d => 175
	i32 2055257422, ; 315: Xamarin.AndroidX.Lifecycle.LiveData.Core.dll => 0x7a80bd4e => 241
	i32 2060060697, ; 316: System.Windows.dll => 0x7aca0819 => 153
	i32 2070888862, ; 317: System.Diagnostics.TraceSource => 0x7b6f419e => 32
	i32 2079903147, ; 318: System.Runtime.dll => 0x7bf8cdab => 115
	i32 2090596640, ; 319: System.Numerics.Vectors => 0x7c9bf920 => 81
	i32 2103459038, ; 320: SQLitePCLRaw.provider.e_sqlite3.dll => 0x7d603cde => 197
	i32 2127167465, ; 321: System.Console => 0x7ec9ffe9 => 20
	i32 2142473426, ; 322: System.Collections.Specialized => 0x7fb38cd2 => 11
	i32 2143790110, ; 323: System.Xml.XmlSerializer.dll => 0x7fc7a41e => 161
	i32 2146852085, ; 324: Microsoft.VisualBasic.dll => 0x7ff65cf5 => 3
	i32 2150663486, ; 325: ko/Microsoft.Maui.Controls.resources => 0x8030853e => 302
	i32 2159891885, ; 326: Microsoft.Maui => 0x80bd55ad => 190
	i32 2165051842, ; 327: ro/Microsoft.Maui.Controls.resources => 0x810c11c2 => 309
	i32 2181898931, ; 328: Microsoft.Extensions.Options.dll => 0x820d22b3 => 184
	i32 2192057212, ; 329: Microsoft.Extensions.Logging.Abstractions => 0x82a8237c => 182
	i32 2193016926, ; 330: System.ObjectModel.dll => 0x82b6c85e => 83
	i32 2201107256, ; 331: Xamarin.KotlinX.Coroutines.Core.Jvm.dll => 0x83323b38 => 285
	i32 2201231467, ; 332: System.Net.Http => 0x8334206b => 63
	i32 2217644978, ; 333: Xamarin.AndroidX.VectorDrawable.Animated.dll => 0x842e93b2 => 268
	i32 2222056684, ; 334: System.Threading.Tasks.Parallel => 0x8471e4ec => 142
	i32 2244775296, ; 335: Xamarin.AndroidX.LocalBroadcastManager => 0x85cc8d80 => 250
	i32 2252106437, ; 336: System.Xml.Serialization.dll => 0x863c6ac5 => 156
	i32 2256313426, ; 337: System.Globalization.Extensions => 0x867c9c52 => 40
	i32 2265110946, ; 338: System.Security.AccessControl.dll => 0x8702d9a2 => 116
	i32 2266799131, ; 339: Microsoft.Extensions.Configuration.Abstractions => 0x871c9c1b => 174
	i32 2267999099, ; 340: Xamarin.Android.Glide.DiskLruCache.dll => 0x872eeb7b => 205
	i32 2270573516, ; 341: fr/Microsoft.Maui.Controls.resources.dll => 0x875633cc => 294
	i32 2279755925, ; 342: Xamarin.AndroidX.RecyclerView.dll => 0x87e25095 => 257
	i32 2289298199, ; 343: th/Microsoft.Maui.Controls.resources => 0x8873eb17 => 313
	i32 2293034957, ; 344: System.ServiceModel.Web.dll => 0x88acefcd => 130
	i32 2295906218, ; 345: System.Net.Sockets => 0x88d8bfaa => 74
	i32 2298471582, ; 346: System.Net.Mail => 0x88ffe49e => 65
	i32 2305521784, ; 347: System.Private.CoreLib.dll => 0x896b7878 => 171
	i32 2315684594, ; 348: Xamarin.AndroidX.Annotation.dll => 0x8a068af2 => 209
	i32 2320631194, ; 349: System.Threading.Tasks.Parallel.dll => 0x8a52059a => 142
	i32 2340441535, ; 350: System.Runtime.InteropServices.RuntimeInformation.dll => 0x8b804dbf => 105
	i32 2344264397, ; 351: System.ValueTuple => 0x8bbaa2cd => 150
	i32 2353062107, ; 352: System.Net.Primitives => 0x8c40e0db => 69
	i32 2354730003, ; 353: Syncfusion.Licensing => 0x8c5a5413 => 198
	i32 2368005991, ; 354: System.Xml.ReaderWriter.dll => 0x8d24e767 => 155
	i32 2369760409, ; 355: tr/Microsoft.Maui.Controls.resources => 0x8d3fac99 => 314
	i32 2371007202, ; 356: Microsoft.Extensions.Configuration => 0x8d52b2e2 => 173
	i32 2378619854, ; 357: System.Security.Cryptography.Csp.dll => 0x8dc6dbce => 120
	i32 2383496789, ; 358: System.Security.Principal.Windows.dll => 0x8e114655 => 126
	i32 2393032527, ; 359: lab1 => 0x8ea2c74f => 0
	i32 2401565422, ; 360: System.Web.HttpUtility => 0x8f24faee => 151
	i32 2403452196, ; 361: Xamarin.AndroidX.Emoji2.dll => 0x8f41c524 => 232
	i32 2421380589, ; 362: System.Threading.Tasks.Dataflow => 0x905355ed => 140
	i32 2421992093, ; 363: nl/Microsoft.Maui.Controls.resources => 0x905caa9d => 305
	i32 2423080555, ; 364: Xamarin.AndroidX.Collection.Ktx.dll => 0x906d466b => 219
	i32 2435356389, ; 365: System.Console.dll => 0x912896e5 => 20
	i32 2435904999, ; 366: System.ComponentModel.DataAnnotations.dll => 0x9130f5e7 => 14
	i32 2454642406, ; 367: System.Text.Encoding.dll => 0x924edee6 => 134
	i32 2458678730, ; 368: System.Net.Sockets.dll => 0x928c75ca => 74
	i32 2459001652, ; 369: System.Linq.Parallel.dll => 0x92916334 => 58
	i32 2465273461, ; 370: SQLitePCLRaw.batteries_v2.dll => 0x92f11675 => 194
	i32 2465532216, ; 371: Xamarin.AndroidX.ConstraintLayout.Core.dll => 0x92f50938 => 222
	i32 2471841756, ; 372: netstandard.dll => 0x93554fdc => 166
	i32 2475788418, ; 373: Java.Interop.dll => 0x93918882 => 167
	i32 2480646305, ; 374: Microsoft.Maui.Controls => 0x93dba8a1 => 188
	i32 2483903535, ; 375: System.ComponentModel.EventBasedAsync => 0x940d5c2f => 15
	i32 2484371297, ; 376: System.Net.ServicePoint => 0x94147f61 => 73
	i32 2490993605, ; 377: System.AppContext.dll => 0x94798bc5 => 6
	i32 2501346920, ; 378: System.Data.DataSetExtensions => 0x95178668 => 23
	i32 2505896520, ; 379: Xamarin.AndroidX.Lifecycle.Runtime.dll => 0x955cf248 => 244
	i32 2520433370, ; 380: sk/Microsoft.Maui.Controls.resources => 0x963ac2da => 311
	i32 2522472828, ; 381: Xamarin.Android.Glide.dll => 0x9659e17c => 203
	i32 2538310050, ; 382: System.Reflection.Emit.Lightweight.dll => 0x974b89a2 => 90
	i32 2562349572, ; 383: Microsoft.CSharp => 0x98ba5a04 => 1
	i32 2570120770, ; 384: System.Text.Encodings.Web => 0x9930ee42 => 135
	i32 2581783588, ; 385: Xamarin.AndroidX.Lifecycle.Runtime.Ktx => 0x99e2e424 => 245
	i32 2581819634, ; 386: Xamarin.AndroidX.VectorDrawable.dll => 0x99e370f2 => 267
	i32 2585220780, ; 387: System.Text.Encoding.Extensions.dll => 0x9a1756ac => 133
	i32 2585805581, ; 388: System.Net.Ping => 0x9a20430d => 68
	i32 2589602615, ; 389: System.Threading.ThreadPool => 0x9a5a3337 => 145
	i32 2605712449, ; 390: Xamarin.KotlinX.Coroutines.Core.Jvm => 0x9b500441 => 285
	i32 2615233544, ; 391: Xamarin.AndroidX.Fragment.Ktx => 0x9be14c08 => 236
	i32 2616218305, ; 392: Microsoft.Extensions.Logging.Debug.dll => 0x9bf052c1 => 183
	i32 2617129537, ; 393: System.Private.Xml.dll => 0x9bfe3a41 => 87
	i32 2618712057, ; 394: System.Reflection.TypeExtensions.dll => 0x9c165ff9 => 95
	i32 2620871830, ; 395: Xamarin.AndroidX.CursorAdapter.dll => 0x9c375496 => 226
	i32 2624644809, ; 396: Xamarin.AndroidX.DynamicAnimation => 0x9c70e6c9 => 231
	i32 2627185994, ; 397: System.Diagnostics.TextWriterTraceListener.dll => 0x9c97ad4a => 30
	i32 2629843544, ; 398: System.IO.Compression.ZipFile.dll => 0x9cc03a58 => 44
	i32 2633051222, ; 399: Xamarin.AndroidX.Lifecycle.LiveData => 0x9cf12c56 => 240
	i32 2663391936, ; 400: Xamarin.Android.Glide.DiskLruCache => 0x9ec022c0 => 205
	i32 2663698177, ; 401: System.Runtime.Loader => 0x9ec4cf01 => 108
	i32 2664396074, ; 402: System.Xml.XDocument.dll => 0x9ecf752a => 157
	i32 2665622720, ; 403: System.Drawing.Primitives => 0x9ee22cc0 => 34
	i32 2676780864, ; 404: System.Data.Common.dll => 0x9f8c6f40 => 22
	i32 2686887180, ; 405: System.Runtime.Serialization.Xml.dll => 0xa026a50c => 113
	i32 2693849962, ; 406: System.IO.dll => 0xa090e36a => 56
	i32 2701096212, ; 407: Xamarin.AndroidX.Tracing.Tracing => 0xa0ff7514 => 265
	i32 2715334215, ; 408: System.Threading.Tasks.dll => 0xa1d8b647 => 143
	i32 2717744543, ; 409: System.Security.Claims => 0xa1fd7d9f => 117
	i32 2719963679, ; 410: System.Security.Cryptography.Cng.dll => 0xa21f5a1f => 119
	i32 2724373263, ; 411: System.Runtime.Numerics.dll => 0xa262a30f => 109
	i32 2732626843, ; 412: Xamarin.AndroidX.Activity => 0xa2e0939b => 207
	i32 2735172069, ; 413: System.Threading.Channels => 0xa30769e5 => 138
	i32 2737747696, ; 414: Xamarin.AndroidX.AppCompat.AppCompatResources.dll => 0xa32eb6f0 => 213
	i32 2740948882, ; 415: System.IO.Pipes.AccessControl => 0xa35f8f92 => 53
	i32 2748088231, ; 416: System.Runtime.InteropServices.JavaScript => 0xa3cc7fa7 => 104
	i32 2758225723, ; 417: Microsoft.Maui.Controls.Xaml => 0xa4672f3b => 189
	i32 2764765095, ; 418: Microsoft.Maui.dll => 0xa4caf7a7 => 190
	i32 2765824710, ; 419: System.Text.Encoding.CodePages.dll => 0xa4db22c6 => 132
	i32 2770495804, ; 420: Xamarin.Jetbrains.Annotations.dll => 0xa522693c => 279
	i32 2778768386, ; 421: Xamarin.AndroidX.ViewPager.dll => 0xa5a0a402 => 270
	i32 2779977773, ; 422: Xamarin.AndroidX.ResourceInspection.Annotation.dll => 0xa5b3182d => 258
	i32 2788224221, ; 423: Xamarin.AndroidX.Fragment.Ktx.dll => 0xa630ecdd => 236
	i32 2801831435, ; 424: Microsoft.Maui.Graphics => 0xa7008e0b => 192
	i32 2802068195, ; 425: uk/Microsoft.Maui.Controls.resources => 0xa7042ae3 => 315
	i32 2803228030, ; 426: System.Xml.XPath.XDocument.dll => 0xa715dd7e => 158
	i32 2806116107, ; 427: es/Microsoft.Maui.Controls.resources.dll => 0xa741ef0b => 292
	i32 2810250172, ; 428: Xamarin.AndroidX.CoordinatorLayout.dll => 0xa78103bc => 223
	i32 2819470561, ; 429: System.Xml.dll => 0xa80db4e1 => 162
	i32 2821205001, ; 430: System.ServiceProcess.dll => 0xa8282c09 => 131
	i32 2821294376, ; 431: Xamarin.AndroidX.ResourceInspection.Annotation => 0xa8298928 => 258
	i32 2824502124, ; 432: System.Xml.XmlDocument => 0xa85a7b6c => 160
	i32 2831556043, ; 433: nl/Microsoft.Maui.Controls.resources.dll => 0xa8c61dcb => 305
	i32 2838993487, ; 434: Xamarin.AndroidX.Lifecycle.ViewModel.Ktx.dll => 0xa9379a4f => 247
	i32 2849599387, ; 435: System.Threading.Overlapped.dll => 0xa9d96f9b => 139
	i32 2853208004, ; 436: Xamarin.AndroidX.ViewPager => 0xaa107fc4 => 270
	i32 2855708567, ; 437: Xamarin.AndroidX.Transition => 0xaa36a797 => 266
	i32 2857259519, ; 438: el/Microsoft.Maui.Controls.resources => 0xaa4e51ff => 291
	i32 2861098320, ; 439: Mono.Android.Export.dll => 0xaa88e550 => 168
	i32 2861189240, ; 440: Microsoft.Maui.Essentials => 0xaa8a4878 => 191
	i32 2868557005, ; 441: Syncfusion.Licensing.dll => 0xaafab4cd => 198
	i32 2870099610, ; 442: Xamarin.AndroidX.Activity.Ktx.dll => 0xab123e9a => 208
	i32 2875164099, ; 443: Jsr305Binding.dll => 0xab5f85c3 => 275
	i32 2875220617, ; 444: System.Globalization.Calendars.dll => 0xab606289 => 39
	i32 2883495834, ; 445: ru/Microsoft.Maui.Controls.resources => 0xabdea79a => 310
	i32 2884993177, ; 446: Xamarin.AndroidX.ExifInterface => 0xabf58099 => 234
	i32 2887636118, ; 447: System.Net.dll => 0xac1dd496 => 80
	i32 2899753641, ; 448: System.IO.UnmanagedMemoryStream => 0xacd6baa9 => 55
	i32 2900621748, ; 449: System.Dynamic.Runtime.dll => 0xace3f9b4 => 36
	i32 2901442782, ; 450: System.Reflection => 0xacf080de => 96
	i32 2905242038, ; 451: mscorlib.dll => 0xad2a79b6 => 165
	i32 2909740682, ; 452: System.Private.CoreLib => 0xad6f1e8a => 171
	i32 2916838712, ; 453: Xamarin.AndroidX.ViewPager2.dll => 0xaddb6d38 => 271
	i32 2919462931, ; 454: System.Numerics.Vectors.dll => 0xae037813 => 81
	i32 2921128767, ; 455: Xamarin.AndroidX.Annotation.Experimental.dll => 0xae1ce33f => 210
	i32 2936416060, ; 456: System.Resources.Reader => 0xaf06273c => 97
	i32 2940926066, ; 457: System.Diagnostics.StackTrace.dll => 0xaf4af872 => 29
	i32 2942453041, ; 458: System.Xml.XPath.XDocument => 0xaf624531 => 158
	i32 2959614098, ; 459: System.ComponentModel.dll => 0xb0682092 => 18
	i32 2968338931, ; 460: System.Security.Principal.Windows => 0xb0ed41f3 => 126
	i32 2971004615, ; 461: Microsoft.Extensions.Options.ConfigurationExtensions.dll => 0xb115eec7 => 185
	i32 2972252294, ; 462: System.Security.Cryptography.Algorithms.dll => 0xb128f886 => 118
	i32 2978675010, ; 463: Xamarin.AndroidX.DrawerLayout => 0xb18af942 => 230
	i32 2987532451, ; 464: Xamarin.AndroidX.Security.SecurityCrypto => 0xb21220a3 => 261
	i32 2996846495, ; 465: Xamarin.AndroidX.Lifecycle.Process.dll => 0xb2a03f9f => 243
	i32 3016983068, ; 466: Xamarin.AndroidX.Startup.StartupRuntime => 0xb3d3821c => 263
	i32 3020703001, ; 467: Microsoft.Extensions.Diagnostics => 0xb40c4519 => 178
	i32 3023353419, ; 468: WindowsBase.dll => 0xb434b64b => 164
	i32 3024354802, ; 469: Xamarin.AndroidX.Legacy.Support.Core.Utils => 0xb443fdf2 => 238
	i32 3038032645, ; 470: _Microsoft.Android.Resource.Designer.dll => 0xb514b305 => 321
	i32 3056245963, ; 471: Xamarin.AndroidX.SavedState.SavedState.Ktx => 0xb62a9ccb => 260
	i32 3057625584, ; 472: Xamarin.AndroidX.Navigation.Common => 0xb63fa9f0 => 251
	i32 3059408633, ; 473: Mono.Android.Runtime => 0xb65adef9 => 169
	i32 3059793426, ; 474: System.ComponentModel.Primitives => 0xb660be12 => 16
	i32 3075834255, ; 475: System.Threading.Tasks => 0xb755818f => 143
	i32 3077302341, ; 476: hu/Microsoft.Maui.Controls.resources.dll => 0xb76be845 => 298
	i32 3090735792, ; 477: System.Security.Cryptography.X509Certificates.dll => 0xb838e2b0 => 124
	i32 3099732863, ; 478: System.Security.Claims.dll => 0xb8c22b7f => 117
	i32 3103600923, ; 479: System.Formats.Asn1 => 0xb8fd311b => 37
	i32 3111772706, ; 480: System.Runtime.Serialization => 0xb979e222 => 114
	i32 3121463068, ; 481: System.IO.FileSystem.AccessControl.dll => 0xba0dbf1c => 46
	i32 3124832203, ; 482: System.Threading.Tasks.Extensions => 0xba4127cb => 141
	i32 3132293585, ; 483: System.Security.AccessControl => 0xbab301d1 => 116
	i32 3147165239, ; 484: System.Diagnostics.Tracing.dll => 0xbb95ee37 => 33
	i32 3147228406, ; 485: Syncfusion.Maui.Core => 0xbb96e4f6 => 199
	i32 3148237826, ; 486: GoogleGson.dll => 0xbba64c02 => 172
	i32 3159123045, ; 487: System.Reflection.Primitives.dll => 0xbc4c6465 => 94
	i32 3160747431, ; 488: System.IO.MemoryMappedFiles => 0xbc652da7 => 52
	i32 3178803400, ; 489: Xamarin.AndroidX.Navigation.Fragment.dll => 0xbd78b0c8 => 252
	i32 3192346100, ; 490: System.Security.SecureString => 0xbe4755f4 => 128
	i32 3193515020, ; 491: System.Web => 0xbe592c0c => 152
	i32 3204380047, ; 492: System.Data.dll => 0xbefef58f => 24
	i32 3209718065, ; 493: System.Xml.XmlDocument.dll => 0xbf506931 => 160
	i32 3211777861, ; 494: Xamarin.AndroidX.DocumentFile => 0xbf6fd745 => 229
	i32 3220365878, ; 495: System.Threading => 0xbff2e236 => 147
	i32 3226221578, ; 496: System.Runtime.Handles.dll => 0xc04c3c0a => 103
	i32 3251039220, ; 497: System.Reflection.DispatchProxy.dll => 0xc1c6ebf4 => 88
	i32 3258312781, ; 498: Xamarin.AndroidX.CardView => 0xc235e84d => 217
	i32 3265493905, ; 499: System.Linq.Queryable.dll => 0xc2a37b91 => 59
	i32 3265893370, ; 500: System.Threading.Tasks.Extensions.dll => 0xc2a993fa => 141
	i32 3277815716, ; 501: System.Resources.Writer.dll => 0xc35f7fa4 => 99
	i32 3279906254, ; 502: Microsoft.Win32.Registry.dll => 0xc37f65ce => 5
	i32 3280506390, ; 503: System.ComponentModel.Annotations.dll => 0xc3888e16 => 13
	i32 3286872994, ; 504: SQLite-net.dll => 0xc3e9b3a2 => 193
	i32 3290767353, ; 505: System.Security.Cryptography.Encoding => 0xc4251ff9 => 121
	i32 3299363146, ; 506: System.Text.Encoding => 0xc4a8494a => 134
	i32 3303498502, ; 507: System.Diagnostics.FileVersionInfo => 0xc4e76306 => 27
	i32 3316684772, ; 508: System.Net.Requests.dll => 0xc5b097e4 => 71
	i32 3317135071, ; 509: Xamarin.AndroidX.CustomView.dll => 0xc5b776df => 227
	i32 3317144872, ; 510: System.Data => 0xc5b79d28 => 24
	i32 3324377930, ; 511: Syncfusion.Maui.Picker.dll => 0xc625fb4a => 200
	i32 3340431453, ; 512: Xamarin.AndroidX.Arch.Core.Runtime => 0xc71af05d => 215
	i32 3345895724, ; 513: Xamarin.AndroidX.ProfileInstaller.ProfileInstaller.dll => 0xc76e512c => 256
	i32 3346324047, ; 514: Xamarin.AndroidX.Navigation.Runtime => 0xc774da4f => 253
	i32 3358260929, ; 515: System.Text.Json => 0xc82afec1 => 136
	i32 3360279109, ; 516: SQLitePCLRaw.core => 0xc849ca45 => 195
	i32 3362336904, ; 517: Xamarin.AndroidX.Activity.Ktx => 0xc8693088 => 208
	i32 3362522851, ; 518: Xamarin.AndroidX.Core => 0xc86c06e3 => 224
	i32 3366347497, ; 519: Java.Interop => 0xc8a662e9 => 167
	i32 3374999561, ; 520: Xamarin.AndroidX.RecyclerView => 0xc92a6809 => 257
	i32 3395150330, ; 521: System.Runtime.CompilerServices.Unsafe.dll => 0xca5de1fa => 100
	i32 3403906625, ; 522: System.Security.Cryptography.OpenSsl.dll => 0xcae37e41 => 122
	i32 3405233483, ; 523: Xamarin.AndroidX.CustomView.PoolingContainer => 0xcaf7bd4b => 228
	i32 3421170118, ; 524: Microsoft.Extensions.Configuration.Binder => 0xcbeae9c6 => 175
	i32 3428513518, ; 525: Microsoft.Extensions.DependencyInjection.dll => 0xcc5af6ee => 176
	i32 3429136800, ; 526: System.Xml => 0xcc6479a0 => 162
	i32 3430777524, ; 527: netstandard => 0xcc7d82b4 => 166
	i32 3441283291, ; 528: Xamarin.AndroidX.DynamicAnimation.dll => 0xcd1dd0db => 231
	i32 3445260447, ; 529: System.Formats.Tar => 0xcd5a809f => 38
	i32 3452344032, ; 530: Microsoft.Maui.Controls.Compatibility.dll => 0xcdc696e0 => 187
	i32 3463511458, ; 531: hr/Microsoft.Maui.Controls.resources.dll => 0xce70fda2 => 297
	i32 3471940407, ; 532: System.ComponentModel.TypeConverter.dll => 0xcef19b37 => 17
	i32 3476120550, ; 533: Mono.Android => 0xcf3163e6 => 170
	i32 3479583265, ; 534: ru/Microsoft.Maui.Controls.resources.dll => 0xcf663a21 => 310
	i32 3485117614, ; 535: System.Text.Json.dll => 0xcfbaacae => 136
	i32 3486566296, ; 536: System.Transactions => 0xcfd0c798 => 149
	i32 3493954962, ; 537: Xamarin.AndroidX.Concurrent.Futures.dll => 0xd0418592 => 220
	i32 3509114376, ; 538: System.Xml.Linq => 0xd128d608 => 154
	i32 3515174580, ; 539: System.Security.dll => 0xd1854eb4 => 129
	i32 3530912306, ; 540: System.Configuration => 0xd2757232 => 19
	i32 3539954161, ; 541: System.Net.HttpListener => 0xd2ff69f1 => 64
	i32 3542658132, ; 542: vi/Microsoft.Maui.Controls.resources => 0xd328ac54 => 316
	i32 3560100363, ; 543: System.Threading.Timer => 0xd432d20b => 146
	i32 3570554715, ; 544: System.IO.FileSystem.AccessControl => 0xd4d2575b => 46
	i32 3596930546, ; 545: de/Microsoft.Maui.Controls.resources => 0xd664cdf2 => 290
	i32 3597029428, ; 546: Xamarin.Android.Glide.GifDecoder.dll => 0xd6665034 => 206
	i32 3598340787, ; 547: System.Net.WebSockets.Client => 0xd67a52b3 => 78
	i32 3608519521, ; 548: System.Linq.dll => 0xd715a361 => 60
	i32 3623444314, ; 549: da/Microsoft.Maui.Controls.resources => 0xd7f95f5a => 289
	i32 3624195450, ; 550: System.Runtime.InteropServices.RuntimeInformation => 0xd804d57a => 105
	i32 3627220390, ; 551: Xamarin.AndroidX.Print.dll => 0xd832fda6 => 255
	i32 3633644679, ; 552: Xamarin.AndroidX.Annotation.Experimental => 0xd8950487 => 210
	i32 3638274909, ; 553: System.IO.FileSystem.Primitives.dll => 0xd8dbab5d => 48
	i32 3641597786, ; 554: Xamarin.AndroidX.Lifecycle.LiveData.Core => 0xd90e5f5a => 241
	i32 3643854240, ; 555: Xamarin.AndroidX.Navigation.Fragment => 0xd930cda0 => 252
	i32 3645089577, ; 556: System.ComponentModel.DataAnnotations => 0xd943a729 => 14
	i32 3647796983, ; 557: pt-BR/Microsoft.Maui.Controls.resources => 0xd96cf6f7 => 307
	i32 3657292374, ; 558: Microsoft.Extensions.Configuration.Abstractions.dll => 0xd9fdda56 => 174
	i32 3660523487, ; 559: System.Net.NetworkInformation => 0xda2f27df => 67
	i32 3662115805, ; 560: he/Microsoft.Maui.Controls.resources => 0xda4773dd => 295
	i32 3672681054, ; 561: Mono.Android.dll => 0xdae8aa5e => 170
	i32 3682565725, ; 562: Xamarin.AndroidX.Browser => 0xdb7f7e5d => 216
	i32 3684561358, ; 563: Xamarin.AndroidX.Concurrent.Futures => 0xdb9df1ce => 220
	i32 3686075795, ; 564: ms/Microsoft.Maui.Controls.resources => 0xdbb50d93 => 303
	i32 3697841164, ; 565: zh-Hant/Microsoft.Maui.Controls.resources.dll => 0xdc68940c => 319
	i32 3700866549, ; 566: System.Net.WebProxy.dll => 0xdc96bdf5 => 77
	i32 3706696989, ; 567: Xamarin.AndroidX.Core.Core.Ktx.dll => 0xdcefb51d => 225
	i32 3716563718, ; 568: System.Runtime.Intrinsics => 0xdd864306 => 107
	i32 3718780102, ; 569: Xamarin.AndroidX.Annotation => 0xdda814c6 => 209
	i32 3724971120, ; 570: Xamarin.AndroidX.Navigation.Common.dll => 0xde068c70 => 251
	i32 3732100267, ; 571: System.Net.NameResolution => 0xde7354ab => 66
	i32 3737834244, ; 572: System.Net.Http.Json.dll => 0xdecad304 => 62
	i32 3748608112, ; 573: System.Diagnostics.DiagnosticSource => 0xdf6f3870 => 202
	i32 3751444290, ; 574: System.Xml.XPath => 0xdf9a7f42 => 159
	i32 3754567612, ; 575: SQLitePCLRaw.provider.e_sqlite3 => 0xdfca27bc => 197
	i32 3786282454, ; 576: Xamarin.AndroidX.Collection => 0xe1ae15d6 => 218
	i32 3792276235, ; 577: System.Collections.NonGeneric => 0xe2098b0b => 10
	i32 3800979733, ; 578: Microsoft.Maui.Controls.Compatibility => 0xe28e5915 => 187
	i32 3802395368, ; 579: System.Collections.Specialized.dll => 0xe2a3f2e8 => 11
	i32 3819260425, ; 580: System.Net.WebProxy => 0xe3a54a09 => 77
	i32 3823082795, ; 581: System.Security.Cryptography.dll => 0xe3df9d2b => 125
	i32 3829621856, ; 582: System.Numerics.dll => 0xe4436460 => 82
	i32 3841636137, ; 583: Microsoft.Extensions.DependencyInjection.Abstractions.dll => 0xe4fab729 => 177
	i32 3844307129, ; 584: System.Net.Mail.dll => 0xe52378b9 => 65
	i32 3849253459, ; 585: System.Runtime.InteropServices.dll => 0xe56ef253 => 106
	i32 3870376305, ; 586: System.Net.HttpListener.dll => 0xe6b14171 => 64
	i32 3873536506, ; 587: System.Security.Principal => 0xe6e179fa => 127
	i32 3875112723, ; 588: System.Security.Cryptography.Encoding.dll => 0xe6f98713 => 121
	i32 3876362041, ; 589: SQLite-net => 0xe70c9739 => 193
	i32 3885497537, ; 590: System.Net.WebHeaderCollection.dll => 0xe797fcc1 => 76
	i32 3885922214, ; 591: Xamarin.AndroidX.Transition.dll => 0xe79e77a6 => 266
	i32 3888767677, ; 592: Xamarin.AndroidX.ProfileInstaller.ProfileInstaller => 0xe7c9e2bd => 256
	i32 3889960447, ; 593: zh-Hans/Microsoft.Maui.Controls.resources.dll => 0xe7dc15ff => 318
	i32 3896106733, ; 594: System.Collections.Concurrent.dll => 0xe839deed => 8
	i32 3896760992, ; 595: Xamarin.AndroidX.Core.dll => 0xe843daa0 => 224
	i32 3901907137, ; 596: Microsoft.VisualBasic.Core.dll => 0xe89260c1 => 2
	i32 3920810846, ; 597: System.IO.Compression.FileSystem.dll => 0xe9b2d35e => 43
	i32 3921031405, ; 598: Xamarin.AndroidX.VersionedParcelable.dll => 0xe9b630ed => 269
	i32 3928044579, ; 599: System.Xml.ReaderWriter => 0xea213423 => 155
	i32 3930554604, ; 600: System.Security.Principal.dll => 0xea4780ec => 127
	i32 3931092270, ; 601: Xamarin.AndroidX.Navigation.UI => 0xea4fb52e => 254
	i32 3945713374, ; 602: System.Data.DataSetExtensions.dll => 0xeb2ecede => 23
	i32 3953953790, ; 603: System.Text.Encoding.CodePages => 0xebac8bfe => 132
	i32 3955647286, ; 604: Xamarin.AndroidX.AppCompat.dll => 0xebc66336 => 212
	i32 3959773229, ; 605: Xamarin.AndroidX.Lifecycle.Process => 0xec05582d => 243
	i32 3980434154, ; 606: th/Microsoft.Maui.Controls.resources.dll => 0xed409aea => 313
	i32 3987592930, ; 607: he/Microsoft.Maui.Controls.resources.dll => 0xedadd6e2 => 295
	i32 4003436829, ; 608: System.Diagnostics.Process.dll => 0xee9f991d => 28
	i32 4015948917, ; 609: Xamarin.AndroidX.Annotation.Jvm.dll => 0xef5e8475 => 211
	i32 4025784931, ; 610: System.Memory => 0xeff49a63 => 61
	i32 4046471985, ; 611: Microsoft.Maui.Controls.Xaml.dll => 0xf1304331 => 189
	i32 4054681211, ; 612: System.Reflection.Emit.ILGeneration => 0xf1ad867b => 89
	i32 4068434129, ; 613: System.Private.Xml.Linq.dll => 0xf27f60d1 => 86
	i32 4070331268, ; 614: id/Microsoft.Maui.Controls.resources => 0xf29c5384 => 299
	i32 4073602200, ; 615: System.Threading.dll => 0xf2ce3c98 => 147
	i32 4094352644, ; 616: Microsoft.Maui.Essentials.dll => 0xf40add04 => 191
	i32 4099507663, ; 617: System.Drawing.dll => 0xf45985cf => 35
	i32 4100113165, ; 618: System.Private.Uri => 0xf462c30d => 85
	i32 4101593132, ; 619: Xamarin.AndroidX.Emoji2 => 0xf479582c => 232
	i32 4102112229, ; 620: pt/Microsoft.Maui.Controls.resources.dll => 0xf48143e5 => 308
	i32 4119206479, ; 621: pl/Microsoft.Maui.Controls.resources => 0xf5861a4f => 306
	i32 4125707920, ; 622: ms/Microsoft.Maui.Controls.resources.dll => 0xf5e94e90 => 303
	i32 4126470640, ; 623: Microsoft.Extensions.DependencyInjection => 0xf5f4f1f0 => 176
	i32 4127667938, ; 624: System.IO.FileSystem.Watcher => 0xf60736e2 => 49
	i32 4130442656, ; 625: System.AppContext => 0xf6318da0 => 6
	i32 4147896353, ; 626: System.Reflection.Emit.ILGeneration.dll => 0xf73be021 => 89
	i32 4151237749, ; 627: System.Core => 0xf76edc75 => 21
	i32 4159265925, ; 628: System.Xml.XmlSerializer => 0xf7e95c85 => 161
	i32 4161255271, ; 629: System.Reflection.TypeExtensions => 0xf807b767 => 95
	i32 4164802419, ; 630: System.IO.FileSystem.Watcher.dll => 0xf83dd773 => 49
	i32 4181436372, ; 631: System.Runtime.Serialization.Primitives => 0xf93ba7d4 => 112
	i32 4182413190, ; 632: Xamarin.AndroidX.Lifecycle.ViewModelSavedState.dll => 0xf94a8f86 => 248
	i32 4185676441, ; 633: System.Security => 0xf97c5a99 => 129
	i32 4196529839, ; 634: System.Net.WebClient.dll => 0xfa21f6af => 75
	i32 4213026141, ; 635: System.Diagnostics.DiagnosticSource.dll => 0xfb1dad5d => 202
	i32 4234116406, ; 636: pt/Microsoft.Maui.Controls.resources => 0xfc5f7d36 => 308
	i32 4256097574, ; 637: Xamarin.AndroidX.Core.Core.Ktx => 0xfdaee526 => 225
	i32 4258378803, ; 638: Xamarin.AndroidX.Lifecycle.ViewModel.Ktx => 0xfdd1b433 => 247
	i32 4260525087, ; 639: System.Buffers => 0xfdf2741f => 7
	i32 4271975918, ; 640: Microsoft.Maui.Controls.dll => 0xfea12dee => 188
	i32 4274976490, ; 641: System.Runtime.Numerics => 0xfecef6ea => 109
	i32 4292120959, ; 642: Xamarin.AndroidX.Lifecycle.ViewModelSavedState => 0xffd4917f => 248
	i32 4294763496 ; 643: Xamarin.AndroidX.ExifInterface.dll => 0xfffce3e8 => 234
], align 4

@assembly_image_cache_indices = dso_local local_unnamed_addr constant [644 x i32] [
	i32 67, ; 0
	i32 66, ; 1
	i32 107, ; 2
	i32 244, ; 3
	i32 278, ; 4
	i32 47, ; 5
	i32 79, ; 6
	i32 144, ; 7
	i32 287, ; 8
	i32 29, ; 9
	i32 123, ; 10
	i32 192, ; 11
	i32 101, ; 12
	i32 179, ; 13
	i32 262, ; 14
	i32 317, ; 15
	i32 106, ; 16
	i32 262, ; 17
	i32 138, ; 18
	i32 282, ; 19
	i32 76, ; 20
	i32 123, ; 21
	i32 13, ; 22
	i32 218, ; 23
	i32 199, ; 24
	i32 131, ; 25
	i32 264, ; 26
	i32 150, ; 27
	i32 316, ; 28
	i32 317, ; 29
	i32 18, ; 30
	i32 216, ; 31
	i32 26, ; 32
	i32 178, ; 33
	i32 238, ; 34
	i32 1, ; 35
	i32 58, ; 36
	i32 41, ; 37
	i32 90, ; 38
	i32 221, ; 39
	i32 146, ; 40
	i32 240, ; 41
	i32 237, ; 42
	i32 288, ; 43
	i32 53, ; 44
	i32 180, ; 45
	i32 68, ; 46
	i32 207, ; 47
	i32 82, ; 48
	i32 301, ; 49
	i32 239, ; 50
	i32 196, ; 51
	i32 320, ; 52
	i32 300, ; 53
	i32 288, ; 54
	i32 130, ; 55
	i32 54, ; 56
	i32 201, ; 57
	i32 148, ; 58
	i32 73, ; 59
	i32 144, ; 60
	i32 61, ; 61
	i32 145, ; 62
	i32 321, ; 63
	i32 164, ; 64
	i32 312, ; 65
	i32 222, ; 66
	i32 12, ; 67
	i32 235, ; 68
	i32 124, ; 69
	i32 151, ; 70
	i32 112, ; 71
	i32 165, ; 72
	i32 163, ; 73
	i32 237, ; 74
	i32 250, ; 75
	i32 83, ; 76
	i32 299, ; 77
	i32 293, ; 78
	i32 186, ; 79
	i32 320, ; 80
	i32 149, ; 81
	i32 296, ; 82
	i32 282, ; 83
	i32 59, ; 84
	i32 181, ; 85
	i32 50, ; 86
	i32 102, ; 87
	i32 113, ; 88
	i32 39, ; 89
	i32 275, ; 90
	i32 273, ; 91
	i32 119, ; 92
	i32 307, ; 93
	i32 51, ; 94
	i32 43, ; 95
	i32 118, ; 96
	i32 227, ; 97
	i32 233, ; 98
	i32 80, ; 99
	i32 135, ; 100
	i32 269, ; 101
	i32 214, ; 102
	i32 8, ; 103
	i32 72, ; 104
	i32 287, ; 105
	i32 154, ; 106
	i32 284, ; 107
	i32 153, ; 108
	i32 201, ; 109
	i32 91, ; 110
	i32 279, ; 111
	i32 44, ; 112
	i32 302, ; 113
	i32 290, ; 114
	i32 283, ; 115
	i32 108, ; 116
	i32 185, ; 117
	i32 128, ; 118
	i32 194, ; 119
	i32 25, ; 120
	i32 204, ; 121
	i32 71, ; 122
	i32 54, ; 123
	i32 45, ; 124
	i32 184, ; 125
	i32 228, ; 126
	i32 22, ; 127
	i32 242, ; 128
	i32 85, ; 129
	i32 42, ; 130
	i32 159, ; 131
	i32 70, ; 132
	i32 255, ; 133
	i32 286, ; 134
	i32 3, ; 135
	i32 41, ; 136
	i32 62, ; 137
	i32 16, ; 138
	i32 52, ; 139
	i32 200, ; 140
	i32 314, ; 141
	i32 278, ; 142
	i32 0, ; 143
	i32 104, ; 144
	i32 283, ; 145
	i32 276, ; 146
	i32 239, ; 147
	i32 33, ; 148
	i32 157, ; 149
	i32 84, ; 150
	i32 31, ; 151
	i32 12, ; 152
	i32 318, ; 153
	i32 50, ; 154
	i32 292, ; 155
	i32 55, ; 156
	i32 259, ; 157
	i32 35, ; 158
	i32 177, ; 159
	i32 289, ; 160
	i32 277, ; 161
	i32 212, ; 162
	i32 34, ; 163
	i32 57, ; 164
	i32 179, ; 165
	i32 246, ; 166
	i32 172, ; 167
	i32 17, ; 168
	i32 280, ; 169
	i32 163, ; 170
	i32 245, ; 171
	i32 183, ; 172
	i32 272, ; 173
	i32 152, ; 174
	i32 268, ; 175
	i32 253, ; 176
	i32 293, ; 177
	i32 306, ; 178
	i32 214, ; 179
	i32 28, ; 180
	i32 51, ; 181
	i32 304, ; 182
	i32 273, ; 183
	i32 5, ; 184
	i32 263, ; 185
	i32 267, ; 186
	i32 219, ; 187
	i32 284, ; 188
	i32 211, ; 189
	i32 195, ; 190
	i32 230, ; 191
	i32 84, ; 192
	i32 272, ; 193
	i32 60, ; 194
	i32 111, ; 195
	i32 56, ; 196
	i32 259, ; 197
	i32 98, ; 198
	i32 19, ; 199
	i32 223, ; 200
	i32 110, ; 201
	i32 100, ; 202
	i32 101, ; 203
	i32 103, ; 204
	i32 276, ; 205
	i32 70, ; 206
	i32 37, ; 207
	i32 31, ; 208
	i32 102, ; 209
	i32 72, ; 210
	i32 9, ; 211
	i32 122, ; 212
	i32 45, ; 213
	i32 213, ; 214
	i32 186, ; 215
	i32 9, ; 216
	i32 42, ; 217
	i32 4, ; 218
	i32 260, ; 219
	i32 296, ; 220
	i32 180, ; 221
	i32 291, ; 222
	i32 30, ; 223
	i32 137, ; 224
	i32 91, ; 225
	i32 92, ; 226
	i32 311, ; 227
	i32 294, ; 228
	i32 48, ; 229
	i32 140, ; 230
	i32 111, ; 231
	i32 139, ; 232
	i32 312, ; 233
	i32 229, ; 234
	i32 319, ; 235
	i32 114, ; 236
	i32 277, ; 237
	i32 156, ; 238
	i32 75, ; 239
	i32 78, ; 240
	i32 249, ; 241
	i32 36, ; 242
	i32 271, ; 243
	i32 233, ; 244
	i32 226, ; 245
	i32 63, ; 246
	i32 137, ; 247
	i32 15, ; 248
	i32 115, ; 249
	i32 265, ; 250
	i32 274, ; 251
	i32 221, ; 252
	i32 47, ; 253
	i32 69, ; 254
	i32 79, ; 255
	i32 125, ; 256
	i32 93, ; 257
	i32 120, ; 258
	i32 281, ; 259
	i32 26, ; 260
	i32 196, ; 261
	i32 242, ; 262
	i32 96, ; 263
	i32 27, ; 264
	i32 217, ; 265
	i32 309, ; 266
	i32 148, ; 267
	i32 168, ; 268
	i32 4, ; 269
	i32 97, ; 270
	i32 32, ; 271
	i32 92, ; 272
	i32 264, ; 273
	i32 181, ; 274
	i32 21, ; 275
	i32 40, ; 276
	i32 169, ; 277
	i32 235, ; 278
	i32 249, ; 279
	i32 304, ; 280
	i32 280, ; 281
	i32 274, ; 282
	i32 254, ; 283
	i32 2, ; 284
	i32 298, ; 285
	i32 133, ; 286
	i32 110, ; 287
	i32 182, ; 288
	i32 315, ; 289
	i32 204, ; 290
	i32 57, ; 291
	i32 94, ; 292
	i32 38, ; 293
	i32 215, ; 294
	i32 25, ; 295
	i32 93, ; 296
	i32 88, ; 297
	i32 98, ; 298
	i32 10, ; 299
	i32 86, ; 300
	i32 99, ; 301
	i32 301, ; 302
	i32 261, ; 303
	i32 173, ; 304
	i32 281, ; 305
	i32 206, ; 306
	i32 7, ; 307
	i32 297, ; 308
	i32 246, ; 309
	i32 286, ; 310
	i32 203, ; 311
	i32 300, ; 312
	i32 87, ; 313
	i32 175, ; 314
	i32 241, ; 315
	i32 153, ; 316
	i32 32, ; 317
	i32 115, ; 318
	i32 81, ; 319
	i32 197, ; 320
	i32 20, ; 321
	i32 11, ; 322
	i32 161, ; 323
	i32 3, ; 324
	i32 302, ; 325
	i32 190, ; 326
	i32 309, ; 327
	i32 184, ; 328
	i32 182, ; 329
	i32 83, ; 330
	i32 285, ; 331
	i32 63, ; 332
	i32 268, ; 333
	i32 142, ; 334
	i32 250, ; 335
	i32 156, ; 336
	i32 40, ; 337
	i32 116, ; 338
	i32 174, ; 339
	i32 205, ; 340
	i32 294, ; 341
	i32 257, ; 342
	i32 313, ; 343
	i32 130, ; 344
	i32 74, ; 345
	i32 65, ; 346
	i32 171, ; 347
	i32 209, ; 348
	i32 142, ; 349
	i32 105, ; 350
	i32 150, ; 351
	i32 69, ; 352
	i32 198, ; 353
	i32 155, ; 354
	i32 314, ; 355
	i32 173, ; 356
	i32 120, ; 357
	i32 126, ; 358
	i32 0, ; 359
	i32 151, ; 360
	i32 232, ; 361
	i32 140, ; 362
	i32 305, ; 363
	i32 219, ; 364
	i32 20, ; 365
	i32 14, ; 366
	i32 134, ; 367
	i32 74, ; 368
	i32 58, ; 369
	i32 194, ; 370
	i32 222, ; 371
	i32 166, ; 372
	i32 167, ; 373
	i32 188, ; 374
	i32 15, ; 375
	i32 73, ; 376
	i32 6, ; 377
	i32 23, ; 378
	i32 244, ; 379
	i32 311, ; 380
	i32 203, ; 381
	i32 90, ; 382
	i32 1, ; 383
	i32 135, ; 384
	i32 245, ; 385
	i32 267, ; 386
	i32 133, ; 387
	i32 68, ; 388
	i32 145, ; 389
	i32 285, ; 390
	i32 236, ; 391
	i32 183, ; 392
	i32 87, ; 393
	i32 95, ; 394
	i32 226, ; 395
	i32 231, ; 396
	i32 30, ; 397
	i32 44, ; 398
	i32 240, ; 399
	i32 205, ; 400
	i32 108, ; 401
	i32 157, ; 402
	i32 34, ; 403
	i32 22, ; 404
	i32 113, ; 405
	i32 56, ; 406
	i32 265, ; 407
	i32 143, ; 408
	i32 117, ; 409
	i32 119, ; 410
	i32 109, ; 411
	i32 207, ; 412
	i32 138, ; 413
	i32 213, ; 414
	i32 53, ; 415
	i32 104, ; 416
	i32 189, ; 417
	i32 190, ; 418
	i32 132, ; 419
	i32 279, ; 420
	i32 270, ; 421
	i32 258, ; 422
	i32 236, ; 423
	i32 192, ; 424
	i32 315, ; 425
	i32 158, ; 426
	i32 292, ; 427
	i32 223, ; 428
	i32 162, ; 429
	i32 131, ; 430
	i32 258, ; 431
	i32 160, ; 432
	i32 305, ; 433
	i32 247, ; 434
	i32 139, ; 435
	i32 270, ; 436
	i32 266, ; 437
	i32 291, ; 438
	i32 168, ; 439
	i32 191, ; 440
	i32 198, ; 441
	i32 208, ; 442
	i32 275, ; 443
	i32 39, ; 444
	i32 310, ; 445
	i32 234, ; 446
	i32 80, ; 447
	i32 55, ; 448
	i32 36, ; 449
	i32 96, ; 450
	i32 165, ; 451
	i32 171, ; 452
	i32 271, ; 453
	i32 81, ; 454
	i32 210, ; 455
	i32 97, ; 456
	i32 29, ; 457
	i32 158, ; 458
	i32 18, ; 459
	i32 126, ; 460
	i32 185, ; 461
	i32 118, ; 462
	i32 230, ; 463
	i32 261, ; 464
	i32 243, ; 465
	i32 263, ; 466
	i32 178, ; 467
	i32 164, ; 468
	i32 238, ; 469
	i32 321, ; 470
	i32 260, ; 471
	i32 251, ; 472
	i32 169, ; 473
	i32 16, ; 474
	i32 143, ; 475
	i32 298, ; 476
	i32 124, ; 477
	i32 117, ; 478
	i32 37, ; 479
	i32 114, ; 480
	i32 46, ; 481
	i32 141, ; 482
	i32 116, ; 483
	i32 33, ; 484
	i32 199, ; 485
	i32 172, ; 486
	i32 94, ; 487
	i32 52, ; 488
	i32 252, ; 489
	i32 128, ; 490
	i32 152, ; 491
	i32 24, ; 492
	i32 160, ; 493
	i32 229, ; 494
	i32 147, ; 495
	i32 103, ; 496
	i32 88, ; 497
	i32 217, ; 498
	i32 59, ; 499
	i32 141, ; 500
	i32 99, ; 501
	i32 5, ; 502
	i32 13, ; 503
	i32 193, ; 504
	i32 121, ; 505
	i32 134, ; 506
	i32 27, ; 507
	i32 71, ; 508
	i32 227, ; 509
	i32 24, ; 510
	i32 200, ; 511
	i32 215, ; 512
	i32 256, ; 513
	i32 253, ; 514
	i32 136, ; 515
	i32 195, ; 516
	i32 208, ; 517
	i32 224, ; 518
	i32 167, ; 519
	i32 257, ; 520
	i32 100, ; 521
	i32 122, ; 522
	i32 228, ; 523
	i32 175, ; 524
	i32 176, ; 525
	i32 162, ; 526
	i32 166, ; 527
	i32 231, ; 528
	i32 38, ; 529
	i32 187, ; 530
	i32 297, ; 531
	i32 17, ; 532
	i32 170, ; 533
	i32 310, ; 534
	i32 136, ; 535
	i32 149, ; 536
	i32 220, ; 537
	i32 154, ; 538
	i32 129, ; 539
	i32 19, ; 540
	i32 64, ; 541
	i32 316, ; 542
	i32 146, ; 543
	i32 46, ; 544
	i32 290, ; 545
	i32 206, ; 546
	i32 78, ; 547
	i32 60, ; 548
	i32 289, ; 549
	i32 105, ; 550
	i32 255, ; 551
	i32 210, ; 552
	i32 48, ; 553
	i32 241, ; 554
	i32 252, ; 555
	i32 14, ; 556
	i32 307, ; 557
	i32 174, ; 558
	i32 67, ; 559
	i32 295, ; 560
	i32 170, ; 561
	i32 216, ; 562
	i32 220, ; 563
	i32 303, ; 564
	i32 319, ; 565
	i32 77, ; 566
	i32 225, ; 567
	i32 107, ; 568
	i32 209, ; 569
	i32 251, ; 570
	i32 66, ; 571
	i32 62, ; 572
	i32 202, ; 573
	i32 159, ; 574
	i32 197, ; 575
	i32 218, ; 576
	i32 10, ; 577
	i32 187, ; 578
	i32 11, ; 579
	i32 77, ; 580
	i32 125, ; 581
	i32 82, ; 582
	i32 177, ; 583
	i32 65, ; 584
	i32 106, ; 585
	i32 64, ; 586
	i32 127, ; 587
	i32 121, ; 588
	i32 193, ; 589
	i32 76, ; 590
	i32 266, ; 591
	i32 256, ; 592
	i32 318, ; 593
	i32 8, ; 594
	i32 224, ; 595
	i32 2, ; 596
	i32 43, ; 597
	i32 269, ; 598
	i32 155, ; 599
	i32 127, ; 600
	i32 254, ; 601
	i32 23, ; 602
	i32 132, ; 603
	i32 212, ; 604
	i32 243, ; 605
	i32 313, ; 606
	i32 295, ; 607
	i32 28, ; 608
	i32 211, ; 609
	i32 61, ; 610
	i32 189, ; 611
	i32 89, ; 612
	i32 86, ; 613
	i32 299, ; 614
	i32 147, ; 615
	i32 191, ; 616
	i32 35, ; 617
	i32 85, ; 618
	i32 232, ; 619
	i32 308, ; 620
	i32 306, ; 621
	i32 303, ; 622
	i32 176, ; 623
	i32 49, ; 624
	i32 6, ; 625
	i32 89, ; 626
	i32 21, ; 627
	i32 161, ; 628
	i32 95, ; 629
	i32 49, ; 630
	i32 112, ; 631
	i32 248, ; 632
	i32 129, ; 633
	i32 75, ; 634
	i32 202, ; 635
	i32 308, ; 636
	i32 225, ; 637
	i32 247, ; 638
	i32 7, ; 639
	i32 188, ; 640
	i32 109, ; 641
	i32 248, ; 642
	i32 234 ; 643
], align 4

@marshal_methods_number_of_classes = dso_local local_unnamed_addr constant i32 0, align 4

@marshal_methods_class_cache = dso_local local_unnamed_addr global [0 x %struct.MarshalMethodsManagedClass] zeroinitializer, align 4

; Names of classes in which marshal methods reside
@mm_class_names = dso_local local_unnamed_addr constant [0 x ptr] zeroinitializer, align 4

@mm_method_names = dso_local local_unnamed_addr constant [1 x %struct.MarshalMethodName] [
	%struct.MarshalMethodName {
		i64 0, ; id 0x0; name: 
		ptr @.MarshalMethodName.0_name; char* name
	} ; 0
], align 8

; get_function_pointer (uint32_t mono_image_index, uint32_t class_index, uint32_t method_token, void*& target_ptr)
@get_function_pointer = internal dso_local unnamed_addr global ptr null, align 4

; Functions

; Function attributes: "min-legal-vector-width"="0" mustprogress "no-trapping-math"="true" nofree norecurse nosync nounwind "stack-protector-buffer-size"="8" uwtable willreturn
define void @xamarin_app_init(ptr nocapture noundef readnone %env, ptr noundef %fn) local_unnamed_addr #0
{
	%fnIsNull = icmp eq ptr %fn, null
	br i1 %fnIsNull, label %1, label %2

1: ; preds = %0
	%putsResult = call noundef i32 @puts(ptr @.str.0)
	call void @abort()
	unreachable 

2: ; preds = %1, %0
	store ptr %fn, ptr @get_function_pointer, align 4, !tbaa !3
	ret void
}

; Strings
@.str.0 = private unnamed_addr constant [40 x i8] c"get_function_pointer MUST be specified\0A\00", align 1

;MarshalMethodName
@.MarshalMethodName.0_name = private unnamed_addr constant [1 x i8] c"\00", align 1

; External functions

; Function attributes: "no-trapping-math"="true" noreturn nounwind "stack-protector-buffer-size"="8"
declare void @abort() local_unnamed_addr #2

; Function attributes: nofree nounwind
declare noundef i32 @puts(ptr noundef) local_unnamed_addr #1
attributes #0 = { "min-legal-vector-width"="0" mustprogress "no-trapping-math"="true" nofree norecurse nosync nounwind "stack-protector-buffer-size"="8" "stackrealign" "target-cpu"="i686" "target-features"="+cx8,+mmx,+sse,+sse2,+sse3,+ssse3,+x87" "tune-cpu"="generic" uwtable willreturn }
attributes #1 = { nofree nounwind }
attributes #2 = { "no-trapping-math"="true" noreturn nounwind "stack-protector-buffer-size"="8" "stackrealign" "target-cpu"="i686" "target-features"="+cx8,+mmx,+sse,+sse2,+sse3,+ssse3,+x87" "tune-cpu"="generic" }

; Metadata
!llvm.module.flags = !{!0, !1, !7}
!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!llvm.ident = !{!2}
!2 = !{!"Xamarin.Android remotes/origin/release/8.0.1xx @ 87e4a6d890397c13b2572ce01d4b57874ecef9b0"}
!3 = !{!4, !4, i64 0}
!4 = !{!"any pointer", !5, i64 0}
!5 = !{!"omnipotent char", !6, i64 0}
!6 = !{!"Simple C++ TBAA"}
!7 = !{i32 1, !"NumRegisterParameters", i32 0}
