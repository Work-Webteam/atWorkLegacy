(function(app) {
  app.AppComponent =
    ng.core.Component({
      selector: 'my-app',
      templateUrl: './sites/all/modules/custom/atwork_premiers_awards_angular/theme/atwork_premiers_award_template.html',
      styleUrl: './sites/all/modules/custom/atwork_premiers_awards_angular/css/atwork_premiers_award.css',
    })
    .Class({
      constructor: function(){}
    });
    console.log("test");
})(window.app || (window.app = {}));