using CommunityToolkit.Maui;
using Microsoft.Extensions.Logging;
using Shpakovsky_253505.Persistense;
using Shpakovsky_253505.Application;
using Shpakovsky_253505.UI;
using Shpakovsky_253505.UI.Services;
using Shpakovsky_253505.Application.BrigadeUseCases.Queries;
using System.Reflection;
using Microsoft.Extensions.Configuration;
using Microsoft.EntityFrameworkCore;
using Shpakovsky_253505.Persistense.Data;

namespace Shpakovsky_253505.UI;

public static class MauiProgram
{
	public static MauiApp CreateMauiApp()
	{
		string settingsStream = "Shpakovsky_253505.UI.appsettings.json";

		var builder = MauiApp.CreateBuilder();

        var a = Assembly.GetExecutingAssembly();
        using var stream = a.GetManifestResourceStream(settingsStream);
        builder.Configuration.AddJsonStream(stream);

        builder
			.UseMauiApp<App>()
            .UseMauiCommunityToolkit()
            .ConfigureFonts(fonts =>
			{
				fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
				fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
			});

        var connStr = builder.Configuration.GetConnectionString("SqliteConnection");
        string dataDirectory = FileSystem.Current.AppDataDirectory + "/";

        connStr = String.Format(connStr, dataDirectory);
		var options = new DbContextOptionsBuilder<AppDbContext>()
			.UseSqlite(connStr)
			.Options;

        builder.Services
			.AddApplication()
			.AddPersistence(options)
            .RegisterPages()
            .RegisterViewModels();


#if DEBUG
        builder.Logging.AddDebug();
#endif

		return builder.Build();
	}
}
