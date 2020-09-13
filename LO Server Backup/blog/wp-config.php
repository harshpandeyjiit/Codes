<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'id5245988_wplahore' );

/** MySQL database username */
define( 'DB_USER', 'id5245988_wplahore' );

/** MySQL database password */
define( 'DB_PASSWORD', 'silverdoe.1' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '>NpKPuHgC23t@a~Fe=l3FfsEz?B&2c=:TgwTmdhD%s~THm%PgjxD=VD!U4gkte6)' );
define( 'SECURE_AUTH_KEY',  '*{`Io2=ldUSEe}0,:m~)x[}W-xD@--w9!$biPq:m{$pX_yb$8K!iW#Sj:Eht_^MH' );
define( 'LOGGED_IN_KEY',    '^%SyuSbwn]0Yj*a1Idb)nr?RTY4bfSlc+%(L)A%d8pV4w4>d,!&f|K;(1X:z,9rr' );
define( 'NONCE_KEY',        '2IEhZ]nIl_$|8>N]9f*n.&}1~P~&|<_lGQ)Eoj30jPZcWn/C*[(YMY`dD?cdX(il' );
define( 'AUTH_SALT',        '4V~/v#=Q4F!jNUtPqylCkqWA>Ri$cDJN/F0Mk#VGU.x@hCC|3t<0Ix7JmdyYW`fV' );
define( 'SECURE_AUTH_SALT', '{:s[`lEO}Y(}j8_Z^.@b|JMPq1&z%9]{[QdMDQSkbLZ4YyX9YloCy6~)#{SF_DFp' );
define( 'LOGGED_IN_SALT',   'XXt^7 K]zbQAvAT#!=Yr8+@PTUv[EsVVJtwg8;hvouy9FO]_K)k{a!*)F-0*.y@w' );
define( 'NONCE_SALT',       'Kk(ad_-a65hfmwI>B1Q!{$5|> I,. l_C<N9`#.<~Z/e.hcZB7QyJF< 8LX u<sb' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
