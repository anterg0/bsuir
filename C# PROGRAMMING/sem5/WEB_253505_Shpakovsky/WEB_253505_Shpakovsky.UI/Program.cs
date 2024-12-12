using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Authentication.OpenIdConnect;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.IdentityModel.Protocols.OpenIdConnect;
using Serilog;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.UI;
using WEB_253505_Shpakovsky.UI.Components;
using WEB_253505_Shpakovsky.UI.HelperClasses;
using WEB_253505_Shpakovsky.UI.Services;
using WEB_253505_Shpakovsky.UI.Services.Authentication;
using WEB_253505_Shpakovsky.UI.Services.Authorization;

var builder = WebApplication.CreateBuilder(args);
builder.Services.AddDbContext<MovieContext>(options =>
    options.UseSqlServer(builder.Configuration.GetConnectionString("MovieContext") ?? throw new InvalidOperationException("Connection string 'MovieContext' not found.")));
builder.Services.AddHttpContextAccessor();
var uriData = builder.Configuration.GetSection("UriData").Get<UriData>();
builder.Services.AddSingleton(uriData);
builder.Services.Configure<KeycloakData>(builder.Configuration.GetSection("Keycloak"));
builder.Services.AddHttpClient<IMovieService, ApiProductService>(opt=> opt.BaseAddress=new Uri(uriData.ApiUri));
builder.Services.AddHttpClient<IGenreService, ApiCategoryService>(opt=> opt.BaseAddress=new Uri(uriData.ApiUri));
builder.Services.AddHttpClient<IFileService, ApiFileService>(opt =>
    opt.BaseAddress = new Uri($"{uriData.ApiUri}Files/"));
builder.Services.AddControllersWithViews();
builder.Services.AddRazorPages();
builder.Services.AddRazorComponents();
builder.Services.AddDistributedMemoryCache();
builder.Services.AddSession();
builder.Services.AddScoped<CartContainer, SessionCart>();
builder.Services.AddSerilog();
Log.Logger = new LoggerConfiguration()
    .ReadFrom.Configuration(new ConfigurationBuilder()
        .AddJsonFile("appsettings.json")
        .Build())
    .CreateLogger();
// builder.Services.AddScoped<CartViewComponent>();
var keycloakData =
    builder.Configuration.GetSection("Keycloak").Get<KeycloakData>();
builder.Services
    .AddAuthentication(options =>
    {
        options.DefaultScheme =
            CookieAuthenticationDefaults.AuthenticationScheme;
        options.DefaultChallengeScheme =
            OpenIdConnectDefaults.AuthenticationScheme;
    })
    .AddCookie()
    .AddJwtBearer()
    .AddOpenIdConnect(options =>
    {
        options.Authority =
            $"{keycloakData.Host}/auth/realms/{keycloakData.Realm}";
        options.ClientId = keycloakData.ClientId;
        options.ClientSecret = keycloakData.ClientSecret;
        options.ResponseType = OpenIdConnectResponseType.Code;
        options.Scope.Add("openid"); // Customize scopes as needed
        options.SaveTokens = true;
        options.RequireHttpsMetadata = false;
        options.MetadataAddress =
            $"{keycloakData.Host}/realms/{keycloakData.Realm}/.well-known/openid-configuration";
    });
builder.Services.AddHttpClient<ITokenAccessor, KeycloakTokenAccessor>();
builder.Services.AddScoped<IAuthService, KeycloakAuthService>();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();
app.UseSession();
app.UseRouting();

app.UseAuthentication();
app.UseAuthorization();
app.UseMiddleware<LoggingMiddleware>();
app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");
app.MapRazorPages();
app.Run();