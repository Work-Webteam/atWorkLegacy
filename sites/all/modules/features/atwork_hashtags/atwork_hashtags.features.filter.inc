<?php
/**
 * @file
 * atwork_hashtags.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function atwork_hashtags_filter_default_formats() {
  $formats = array();

  // Exported format: Comment.
  $formats['comment'] = array(
    'format' => 'comment',
    'name' => 'Comment',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'wysiwyg' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'valid_elements' => 'a[!href|target<_blank|title],
div[align<center?justify?left?right],
p[align<center?justify?left?right],
br,span,em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd',
          'allow_comments' => 0,
          'nofollow_policy' => 'whitelist',
          'nofollow_domains' => array(
            0 => 'hinde.dmz',
          ),
          'style_color' => array(
            'color' => 0,
            'background' => 0,
            'background-color' => 0,
            'background-image' => 0,
            'background-repeat' => 0,
            'background-attachment' => 0,
            'background-position' => 0,
          ),
          'style_font' => array(
            'font' => 0,
            'font-family' => 0,
            'font-size' => 0,
            'font-size-adjust' => 0,
            'font-stretch' => 0,
            'font-style' => 0,
            'font-variant' => 0,
            'font-weight' => 0,
          ),
          'style_text' => array(
            'text-align' => 0,
            'text-decoration' => 0,
            'text-indent' => 0,
            'text-transform' => 0,
            'letter-spacing' => 0,
            'word-spacing' => 0,
            'white-space' => 0,
            'direction' => 0,
            'unicode-bidi' => 0,
          ),
          'style_box' => array(
            'margin' => 0,
            'margin-top' => 0,
            'margin-right' => 0,
            'margin-bottom' => 0,
            'margin-left' => 0,
            'padding' => 0,
            'padding-top' => 0,
            'padding-right' => 0,
            'padding-bottom' => 0,
            'padding-left' => 0,
          ),
          'style_border-1' => array(
            'border' => 0,
            'border-top' => 0,
            'border-right' => 0,
            'border-bottom' => 0,
            'border-left' => 0,
            'border-width' => 0,
            'border-top-width' => 0,
            'border-right-width' => 0,
            'border-bottom-width' => 0,
            'border-left-width' => 0,
          ),
          'style_border-2' => array(
            'border-color' => 0,
            'border-top-color' => 0,
            'border-right-color' => 0,
            'border-bottom-color' => 0,
            'border-left-color' => 0,
            'border-style' => 0,
            'border-top-style' => 0,
            'border-right-style' => 0,
            'border-bottom-style' => 0,
            'border-left-style' => 0,
          ),
          'style_dimension' => array(
            'height' => 0,
            'line-height' => 0,
            'max-height' => 0,
            'max-width' => 0,
            'min-height' => 0,
            'min-width' => 0,
            'width' => 0,
          ),
          'style_positioning' => array(
            'bottom' => 0,
            'clip' => 0,
            'left' => 0,
            'overflow' => 0,
            'right' => 0,
            'top' => 0,
            'vertical-align' => 0,
            'z-index' => 0,
          ),
          'style_layout' => array(
            'clear' => 0,
            'display' => 0,
            'float' => 0,
            'position' => 0,
            'visibility' => 0,
          ),
          'style_list' => array(
            'list-style' => 0,
            'list-style-image' => 0,
            'list-style-position' => 0,
            'list-style-type' => 0,
          ),
          'style_table' => array(
            'border-collapse' => 0,
            'border-spacing' => 0,
            'caption-side' => 0,
            'empty-cells' => 0,
            'table-layout' => 0,
          ),
          'style_user' => array(
            'cursor' => 0,
            'outline' => 0,
            'outline-width' => 0,
            'outline-style' => 0,
            'outline-color' => 0,
            'zoom' => 0,
          ),
          'rule_valid_classes' => array(),
          'rule_valid_ids' => array(),
          'rule_style_urls' => array(),
        ),
      ),
      'filter_url' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => -42,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -40,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_hashtags' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'wysiwyg' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'valid_elements' => '@[id|class|style|title],
h2,h3,h4,h5,
a[rel|rev|charset|hreflang|tabindex|accesskey|type|name|href|target|title|class],
strong/b,em/i,strike,u,
#p,-ol[type|compact],-ul[type|compact],-li,br,
img[longdesc|usemap|src|border|alt=|title|hspace|vspace|width|height|align],
-sub,-sup,-blockquote,
-table[border|cellspacing|cellpadding|width|frame|rules|height|align|summary|bgcolor|background|bordercolor],
-tr[rowspan|width|height|align|valign|bgcolor|background|bordercolor],
tbody,thead,tfoot,
#td[colspan|rowspan|width|height|align|valign|bgcolor|background|bordercolor|scope],
#th[colspan|rowspan|width|height|align|valign|scope],
caption,-div,-span,-code,-pre,address,-h3,-h4,-h5,-h6,hr[size|noshade],
-font[face|size|color],dd,dl,dt,cite,abbr,acronym,del[datetime|cite],ins[datetime|cite],
bdo,col[align|char|charoff|span|valign|width],
colgroup[align|char|charoff|span|valign|width],dfn,fieldset,
kbd,legend,q[cite],samp,small,tt,var,big',
          'allow_comments' => 1,
          'nofollow_policy' => 'whitelist',
          'nofollow_domains' => array(
            0 => 'hinde.dmz',
            2 => 'gww.gov.bc.ca',
          ),
          'style_color' => array(
            'color' => 0,
            'background' => 0,
            'background-color' => 0,
            'background-image' => 0,
            'background-repeat' => 0,
            'background-attachment' => 0,
            'background-position' => 0,
          ),
          'style_font' => array(
            'font-size' => 'font-size',
            'font-style' => 'font-style',
            'font-weight' => 'font-weight',
            'font' => 0,
            'font-family' => 0,
            'font-size-adjust' => 0,
            'font-stretch' => 0,
            'font-variant' => 0,
          ),
          'style_text' => array(
            'text-align' => 'text-align',
            'text-decoration' => 'text-decoration',
            'text-indent' => 'text-indent',
            'text-transform' => 'text-transform',
            'letter-spacing' => 0,
            'word-spacing' => 0,
            'white-space' => 0,
            'direction' => 0,
            'unicode-bidi' => 0,
          ),
          'style_box' => array(
            'margin' => 'margin',
            'margin-top' => 'margin-top',
            'margin-right' => 'margin-right',
            'margin-bottom' => 'margin-bottom',
            'margin-left' => 'margin-left',
            'padding' => 'padding',
            'padding-top' => 'padding-top',
            'padding-right' => 'padding-right',
            'padding-bottom' => 'padding-bottom',
            'padding-left' => 'padding-left',
          ),
          'style_border-1' => array(
            'border' => 0,
            'border-top' => 0,
            'border-right' => 0,
            'border-bottom' => 0,
            'border-left' => 0,
            'border-width' => 0,
            'border-top-width' => 0,
            'border-right-width' => 0,
            'border-bottom-width' => 0,
            'border-left-width' => 0,
          ),
          'style_border-2' => array(
            'border-color' => 0,
            'border-top-color' => 0,
            'border-right-color' => 0,
            'border-bottom-color' => 0,
            'border-left-color' => 0,
            'border-style' => 0,
            'border-top-style' => 0,
            'border-right-style' => 0,
            'border-bottom-style' => 0,
            'border-left-style' => 0,
          ),
          'style_dimension' => array(
            'height' => 'height',
            'line-height' => 'line-height',
            'width' => 'width',
            'max-height' => 0,
            'max-width' => 0,
            'min-height' => 0,
            'min-width' => 0,
          ),
          'style_positioning' => array(
            'bottom' => 0,
            'clip' => 0,
            'left' => 0,
            'overflow' => 0,
            'right' => 0,
            'top' => 0,
            'vertical-align' => 0,
            'z-index' => 0,
          ),
          'style_layout' => array(
            'clear' => 'clear',
            'float' => 'float',
            'display' => 0,
            'position' => 0,
            'visibility' => 0,
          ),
          'style_list' => array(
            'list-style' => 0,
            'list-style-image' => 0,
            'list-style-position' => 0,
            'list-style-type' => 0,
          ),
          'style_table' => array(
            'border-collapse' => 0,
            'border-spacing' => 0,
            'caption-side' => 0,
            'empty-cells' => 0,
            'table-layout' => 0,
          ),
          'style_user' => array(
            'cursor' => 0,
            'outline' => 0,
            'outline-width' => 0,
            'outline-style' => 0,
            'outline-color' => 0,
            'zoom' => 0,
          ),
          'rule_valid_classes' => array(
            0 => 'rteindent1',
            2 => 'rteindent2',
            4 => 'rteindent3',
            6 => 'rteindent4',
            8 => 'rteleft',
            10 => 'rtecenter',
            12 => 'rteright',
            14 => 'rtejustify',
            16 => 'feature_box_blue',
            18 => 'feature_box_yellow',
            20 => 'block',
            22 => 'block-*',
            24 => 'clearfix',
            26 => 'even',
            28 => 'odd',
            30 => 'zeroborder_table',
            32 => 'latest-news-placeholder',
            34 => 'views',
            36 => 'views-*',
            38 => 'first',
            40 => 'last',
            42 => 'region',
            44 => 'region-*',
            46 => 'content',
            48 => 'front',
          ),
          'rule_valid_ids' => array(
            0 => 'block-*',
            2 => 'arrc-home',
            4 => 'latest-news-arrc',
            6 => 'latest-blogs-arrc',
          ),
          'rule_style_urls' => array(),
        ),
      ),
      'filter_url' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'insert_block' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(
          'check_roles' => 0,
        ),
      ),
      'media_filter' => array(
        'weight' => -39,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -37,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_hashtags' => array(
        'weight' => -35,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Filtered No Editor.
  $formats['filtered_no_editor'] = array(
    'format' => 'filtered_no_editor',
    'name' => 'Filtered No Editor',
    'cache' => 1,
    'status' => 1,
    'weight' => -4,
    'filters' => array(
      'filter_htmlcorrector' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_html' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <img> <p> <br>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_hashtags' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'redirect_filter' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'insert_block' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(
          'check_roles' => 0,
        ),
      ),
      'media_filter' => array(
        'weight' => -41,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -39,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_hashtags' => array(
        'weight' => -35,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -6,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_hashtags' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
